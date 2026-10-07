# Detect the OS using uname
UNAME_S := $(shell uname -s)

# If the OS is FreeBSD, use gmake instead of make
ifeq ($(UNAME_S), FreeBSD)
    MAKE ?= gmake
endif

UUIDGEN ?= uuidgen

# So one can say: make help
define HELP_TEXT

This Makefile is suitable for building small C++ projects.
It requires very little extra configuration.
It assumes a GNU C++ compiler, and GNU Make:
[Make manual](https://www.gnu.org/software/make/manual/)
It was written for Linux, but has been reported to work on Macs and under
MinGW64. It does not seem to break when make is told to run parallel jobs.

## Most basic use:

Put Makefile and sources in one directory and there issue the command:

    make

To remove all the generated files (which should seldom be necessary):

    make clean

## Default behavior:

The Makefile causes `make` to want to build programs, or if there
are no program sources, to build a convenience library. To do so, the
following steps are taken.

* Flexc++ will be called on any scanner specification files.
* Bisonc++ will be called on any parser specification files (grammars).
* C++ source files and internal headers will be preprocessed in order to
  determine their include dependencies.
  [internal headers explained](https://stackoverflow.com/questions/11063355/is-anyone-familiar-with-the-implementation-in-internal-header-ih)
* If included anywhere, C++ internal header files will be precompiled.
* C++ source files will be compiled into object files.
* A convenience library will be composed of all non-program object files.
* Program object files (detected by grepping the source for a `main`
  function) will be linked against the convenience library to become
  executable programs.

Because the Makefile detects which files include which others, updating a
header file will cause all source files that (indirectly) include it to be
remade. On one hand, this consumes time. On the other hand it saves time by
keeping sources and headers in sync, so `make clean` should seldom have to be
run.

## Influencing the Makefile:

The Makefile accepts the usual variables (CXX, CXXFLAGS, CPPFLAGS,
LDFLAGS etc.) as well as FLEXCXX (defaults to: $(FLEXCXX)) and BISONCXX
(defaults to: $(BISONCXX)) These can be set in the usual ways:
[How variables get their values](https://www.gnu.org/software/make/manual/html_node/Values.html#Values)

They can also be set in a file `hooks.mk`, which if it exists, will be
included. Extensions can be set there too, though it should seldom be
necessary, as they auto-adapt to files found.

    CXX_SOURCE_EXTENSION (defaults to: $(CXX_SOURCE_EXTENSION))
    CXX_HEADER_EXTENSION (defaults to: $(CXX_HEADER_EXTENSION))
    CXX_INTERNAL_HEADER_EXTENSION (defaults to: $(CXX_INTERNAL_HEADER_EXTENSION))
    FLEXCXX_SCANNERSPEC_EXTENSION (defaults to: $(FLEXCXX_SCANNERSPEC_EXTENSION))
    BISONCXX_PARSERSPEC_EXTENSION (defaults to: $(BISONCXX_PARSERSPEC_EXTENSION))

When setting extensions, do NOT include the dot in the extension!
DEPDIR (defaults to: $(DEPDIR)) can also be set but is best left alone.

Some variables change the behaviour more extensively:

    VERBOSE=yes causes commands in recipes to be echoed.
    DEP=no      causes dependency analysis to be skipped.
    PCH=no      prevents precompiled headers from being built,
                but not necessarily from being used if they exist.

Note that without analyzing dependencies, Make will not know which
source file includes which internal header, so it will not create or
update precompiled headers.

## Creating files from templates:

Some files can be created from templates integrated in this Makefile.
E.g.:

    mkdir mc
    make mc/myclass.hh
    make mc/myclass.ih
    make mc/ctor1.cc
    mkdir parser
    make parser/grammar.bc++
    make parser/tokenizer.fc++
    make myprog.cc:program

The command for creating a program source differs because it shares its
file extension with non-program sources.
To make header files, a utility to create uuids must be present and configured
near the top of this file.
It is convenient to create the header first, because the template for the
internal header will subsequently find and include it. The template for
source files will find the internal header in turn.

## Making submission zip files.

Try:
    make zip
This requires a metadata.txt in the set dir and order.txt files in the
exercise dirs. Make can generate examples, but you need to edit them.

## Submitting.

Try:
    make submit
This will create metadata.txt (if absent), and generate order.txt files
in each exercise directory (if absent). Review them, then run 'make zip'.

## Static analysis.

On Linux/GCC:     make pedantic
On macOS/Clang:   make pedantic   (strict warnings build)
                  make analyze    (Clang static analyzer)

endef

CXX = g++-16



ifneq ($(CURDIR),$(firstword $(CURDIR)))
    $(error There are spaces in the path to your current directory. Make and this Makefile in particular don't handle that.)
endif

# Recursive wildcard to find all files in the current directory and subdirs.
# Using a $(shell find...) would also work, but depend on the find utility.
rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

# Simply list all files we can find.
ALL_FILES := $(patsubst ./%,%,$(call rwildcard,.,*))

# We recognize files by their extensions, because file magic doesn't always
# work to distinguish C++ from C.

# Autodetection of file extensions.
first_extension_found = $(patsubst .%,%,$(or $(firstword $(foreach X,$1,$(filter %.$X,$(suffix $(ALL_FILES))))),$(firstword $1)))

CXXFLAGS ?= -std=c++26 -Wall -Werror
LDFLAGS += -Wl,-ld_classic
# -pedantic -fsanitize=address,leak,null,bounds,object-size,pointer-overflow,undefined -fanalyzer -Wno-unused-variable -Wstrict-aliasing'
#LDFLAGS += -lrt -ldl -lpthread -lm -lz -ltinfo

# Detect the compiler so we can pick flags that it actually understands.
# macOS ships Clang, which does not support GCC's -fanalyzer or -Wanalyzer-*.
CXX_IS_CLANG := $(shell $(CXX) --version 2>/dev/null | grep -qi clang && echo yes)

# Strict warnings understood by both GCC and Clang.
PEDANTICFLAGS_COMMON := \
  -Wall -Wextra -Wpedantic \
  -Waddress \
  -Wshadow -Wconversion -Wsign-conversion \
  -Wcast-align -Wcast-qual -Wold-style-cast \
  -Wfloat-equal -Wformat=2 -Wformat-security \
  -Wnull-dereference -Wdouble-promotion \
  -Woverloaded-virtual -Wnon-virtual-dtor \
  -Wswitch-default -Wswitch-enum \
  -Wredundant-decls -Wmissing-declarations \
  -Wstrict-overflow=5 -Wextra-semi \
  -Wmissing-braces \
  -Wplacement-new \
  -Wparentheses \
  -Wswitch \
  -Wdeprecated-declarations \
  -g -fsanitize=address,undefined

ifeq ($(CXX_IS_CLANG),yes)
  # macOS / Clang: use Clang's built-in static analyzer.
  PEDANTICFLAGS := $(PEDANTICFLAGS_COMMON)
else
  # GCC on Linux: use GCC's -fanalyzer and analyzer warnings.
  PEDANTICFLAGS := $(PEDANTICFLAGS_COMMON) \
    -Wuseless-cast \
    -fanalyzer \
    -Wanalyzer-double-free \
    -Wanalyzer-double-fclose \
    -Wanalyzer-jump-through-null \
    -Wanalyzer-malloc-leak \
    -Wanalyzer-mismatching-deallocation \
    -Wanalyzer-out-of-bounds \
    -Wanalyzer-overlapping-buffers
endif


CURRENT_MAKEFILE = $(firstword $(MAKEFILE_LIST))

# The file hooks.mk will be included if it exists.
# You could put project-specific settings there.
-include hooks.mk

# Extensions can be set here, or in the environment:
# https://www.gnu.org/software/make/manual/html_node/Environment.html#Environment
CXX_SOURCE_EXTENSION ?= $(call first_extension_found, cc cpp C)
# Some use h
CXX_HEADER_EXTENSION ?= $(call first_extension_found, hh hpp H h)
CXX_INTERNAL_HEADER_EXTENSION ?= $(call first_extension_found, ihh ihpp IH ih)
CXX_PCH_EXTENSION ?= $(CXX_INTERNAL_HEADER_EXTENSION).gch
CXX_OBJECT_EXTENSION ?= $(CXX_SOURCE_EXTENSION).o
DEP_EXTENSION ?= dep

FLEXCXX_SCANNERSPEC_EXTENSION ?= $(call first_extension_found, fc++ fcpp fcxx flexc++ flexcpp flexcxx )
BISONCXX_PARSERSPEC_EXTENSION ?= $(call first_extension_found, bc++ bcpp bcxx bisonc++ bisoncpp bisoncxx )

# By default, this Makefile does not echo recipe commands. But it can.
# Try: 'make VERBOSE=1'
VERBOSE ?= false

# We use precompiled headers by default. But they can be turned off.
# Try: make PCH=no
PCH ?= true

# We analyze and heed generated dependencies by default. But they can be
# turned off. Try: make DEP=no
DEP ?= true

# The name of our convenience library.
CONVLIB = $(notdir $(CURDIR))
CONVLIB_EXTENSION = a
CONVLIB_FILE = lib$(CONVLIB).$(CONVLIB_EXTENSION)

SHAREDLIB = $(notdir $(CURDIR))
SHAREDLIB_EXTENSION = so
SHAREDLIB_FILE = lib$(SHAREDLIB).$(SHAREDLIB_EXTENSION)

# Directory where dependencies are stored.
DEPDIR ?= generated_deps

FLEXCXX ?= flexc++
BISONCXX ?= bisonc++

## No editing below this line unless you know what you're doing. ##

# This Makefile requires GNU Make.
DETECTED_MAKEVERSION = $(shell $(MAKE) --version)
ifneq ($(firstword $(filter GNU,$(DETECTED_MAKEVERSION))),GNU)
    $(error This Makefile requires GNU Make. Detected: $(DETECTED_MAKEVERSION))
endif
undefine DETECTED_MAKEVERSION

# Use any of these words to indicate true or false.
boolalpha = $(or \
   $(if $(filter $(1),t true  True  TRUE  yes Yes YES YESS! on  On  ON  one  One  ONE  1),true,),\
   $(if $(filter $(1),f false False FALSE no  No  NO  NOO!  off Off OFF zero Zero ZERO 0),false,),\
   $(if $(strip $(1)),,false),\
   $(error cannot interpret $(1) as boolean)\
)

# NEWLINE is for use with printf, which is more reliable than echo.
define NEWLINE


endef
#SP is for alignments

USE_PRECOMPILED_HEADERS := $(call boolalpha,$(PCH))
undefine PCH

USE_GENERATED_DEPENDENCIES := $(call boolalpha,$(DEP))
undefine DEP

# QUIET is a '@', unless VERBOSE is true.
QUIET := $(if $(filter true,$(call boolalpha,$(VERBOSE))),,@)
undefine VERBOSE

# Acts as 'dir', but may return the empty string instead of './'
maybe_dir=$(filter-out ./,$(dir $1))

# On e.g. foo/bar/baz returns foo/bar/ foo/
rdir=$(foreach d,$(call maybe_dir,$1),$d $(call rdir,$(patsubst %/,%,$d)))

# Reverses a word list, to list deepest directories first after sort.
reverse=$(if $(wordlist 2,2,$(1)),$(call reverse,$(wordlist 2,$(words $(1)),$(1))) $(firstword $(1)),$(1))

# Useful to remove a tree of empty dirs, recursively:
# Lists dirs recursively, deepest first, with no duplicates.
rdirs=$(call reverse,$(sort $(foreach dir,$1,$(call rdir,$(dir)))))

deps_of = $(addprefix $(DEPDIR)/,$(addsuffix .$(DEP_EXTENSION),$(1)))

# Anything with a CXX_SOURCE_EXTENSION is a C++ source file.
CXX_SOURCES := $(filter %.$(CXX_SOURCE_EXTENSION),$(ALL_FILES))

# Get object names by replacing the extension.
CXX_OBJECTS := $(CXX_SOURCES:%.$(CXX_SOURCE_EXTENSION)=%.$(CXX_OBJECT_EXTENSION))
CXX_SOURCE_DEPS := $(call deps_of,$(CXX_SOURCES))

# To detect a main() function in a source file.
# Not bulletproof, but KISS.
MAIN_REGEX := int[[:space:]]+main[[:space:]]*\(

# Anything that mentions a main function is a program source.
CXX_PROG_SOURCES := $(if $(CXX_SOURCES),$(shell grep -El '$(MAIN_REGEX)' $(CXX_SOURCES)))
CXX_PROG_OBJECTS := $(patsubst %.$(CXX_SOURCE_EXTENSION),%.$(CXX_OBJECT_EXTENSION),$(CXX_PROG_SOURCES))
CXX_PROGS := $(CXX_PROG_SOURCES:%.$(CXX_SOURCE_EXTENSION)=%)
CXX_TESTPROGS := $(filter tests/%,$(CXX_PROGS))

# Sources that aren't program sources, are non-program sources.
CXX_NONPROG_SOURCES := $(filter-out $(CXX_PROG_SOURCES),$(CXX_SOURCES))
CXX_NONPROG_OBJECTS := $(CXX_NONPROG_SOURCES:%.$(CXX_SOURCE_EXTENSION)=%.$(CXX_OBJECT_EXTENSION))

CXX_INTERNAL_HEADERS := $(filter %.$(CXX_INTERNAL_HEADER_EXTENSION),$(ALL_FILES))

# From every internal header we can build a precompiled (internal) header.
CXX_PRECOMPILED_HEADERS := $(CXX_INTERNAL_HEADERS:%=%.gch)
CXX_PCH_DEPS := $(call deps_of,$(CXX_INTERNAL_HEADERS))

FLEXCXX_SCANNERSPECS := $(filter %.$(FLEXCXX_SCANNERSPEC_EXTENSION),$(ALL_FILES))
FLEXCXX_DEPS := $(call deps_of,$(FLEXCXX_SCANNERSPECS))

BISONCXX_PARSERSPECS := $(filter %.$(BISONCXX_PARSERSPEC_EXTENSION),$(ALL_FILES))
BISONCXX_DEPS := $(call deps_of,$(BISONCXX_PARSERSPECS))

###

ALL_DEPS = $(CXX_SOURCE_DEPS) $(CXX_PCH_DEPS) $(FLEXCXX_DEPS) $(BISONCXX_DEPS)

# Could be used to suppress all built-in rules.
.SUFFIXES:

# Suppress making .o from .cc, because we only want to create .cc.o
#%.o: %.$(CXX_SOURCE_EXTENSION)

define RUN-CPPCOMPILE
	$(ECHO_ACTION)
	$(QUIET) $(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<
endef

# Cancel the built-in rules for C++ sources/objects.
%.o: %.cpp
%.o: %.cc
%.o: %.C

# Rules for creating C++ object files.
# To allow for a separate C library, *.cc builds *.cc.o, not *.o.
%.cpp.o: %.cpp ; $(RUN-CPPCOMPILE)
%.cc.o: %.cc   ; $(RUN-CPPCOMPILE)
%.C.o: %.C     ; $(RUN-CPPCOMPILE)

###

# Default target: to make all programs, or at least the convenience library.
all: $(CXX_PROGS) $(if $(CXX_NONPROG_SOURCES),$(CONVLIB_FILE))

# Assumption: all programs need the convenience library.
$(CXX_PROGS): $(CONVLIB_FILE)

# To create an executable program is called: 'Linking'.
$(CXX_PROGS): METHOD = Link       
$(CXX_PROGS): LDFLAGS += -L. -l$(CONVLIB)

$(CXX_OBJECTS): METHOD = Compile    
$(CXX_OBJECTS): INPUTS = $(filter %.$(CXX_SOURCE_EXTENSION),$^)
$(CXX_OBJECTS): CXXFLAGS += -c

$(CONVLIB_FILE): METHOD = Collect
$(SHAREDLIB_FILE): METHOD = Collect

$(CXX_PRECOMPILED_HEADERS): METHOD = Pre-compile
$(CXX_PRECOMPILED_HEADERS): INPUTS = $(filter %.$(CXX_INTERNAL_HEADER_EXTENSION),$^)

# When compiling a precompiled header, specify that it's a header.
$(CXX_PRECOMPILED_HEADERS): CXXFLAGS += -x c++-header

# When a source file is deleted, the object files may linger. Let Make warn then.
GENERATED_EXTENSIONS = $(CXX_OBJECT_EXTENSION) $(CONVLIB_EXTENSION) $(SHAREDLIB_EXTENSION) $(CXX_PCH_EXTENSION) $(DEP_EXTENSION)
#$(info generated extensions: $(GENERATED_EXTENSIONS))
KNOWN_GENERATED_FILES = $(CONVLIB_FILE) $(SHAREDLIB_FILE) $(CXX_OBJECTS) $(CXX_PRECOMPILED_HEADERS) $(ALL_DEPS)
#$(info known generated: $(KNOWN_GENERATED_FILES))
EVER_GENERATED_FILES = $(filter $(addefix %.,$(GENERATED_EXTENSIONS)),$(ALL_FILES))
#$(info ever generated: $(EVER_GENERATED_FILES))
UNKNOWN_GENERATED_FILES = $(filter-out $(KNOWN_GENERATED_FILES),$(EVER_GENERATED_FILES))
#$(info unknown generated: $(UNKNOWN_GENERATED_FILES))
ifneq (,$(UNKNOWN_GENERATED_FILES))
    $(warning $(NEWLINE)Warning: Make may once have generated, but cannot update any more the following files:$(NEWLINE)$(NEWLINE)  $(UNKNOWN_GENERATED_FILES)$(NEWLINE)$(NEWLINE)Perhaps their sources do not exist any more. Consider cleaning them up.)
endif

# Action tells whether we're updating or creating.
ACTION = $(if $(filter $@,$(ALL_FILES)),->,=>)
# This output usually shows instead of the actual command.
ECHO_ACTION = @echo "    [ $(METHOD)  $(or $(INPUTS),$^)\t$(ACTION)\t$(or $(TARGET),$@)\t]"

# A rule says two things:
# 1. To build any of the target, i.e. $(CONVLIB_FILE),
#    we need the prerequisites, i.e. $(CXX_NONPROG_OBJECTS)
# 2. If any of the preprequisites are newer than the target,
#    we need to rebuild the target.
$(CONVLIB_FILE): $(CXX_NONPROG_OBJECTS)
	$(ECHO_ACTION)
	$(QUIET) $(AR) rcs $@ $^
# In the recipe of the rule,
# $@ is the target, i.e. $(CONVLIB_FILE)
# $^ is the list of preprequisites, i.e. $(CXX_NONPROG_OBJECTS)

shared: $(SHAREDLIB_FILE)

$(SHAREDLIB_FILE): $(CXX_NONPROG_OBJECTS)
	$(ECHO_ACTION)
	$(QUIET) $(CXX) --shared $(LDFLAGS) -o $@ $^

# We don't archive object files member my member, because
# 1. the member is a transient prerequisite that causes remakes,
# 2. allegedly it's slow on large projects,
# 3. the individual archiving actions clutter our output,
# 4. it won't work with parallel Make.

# If any program object file is newer than the program itself,
# we rebuild the program, by linking the object file against the convenience library.
$(CXX_PROGS): %: %.$(CXX_OBJECT_EXTENSION)
	$(ECHO_ACTION)
	$(QUIET) $(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

# If the source is newer than its object, we compile it.
$(CXX_OBJECTS): %.$(CXX_OBJECT_EXTENSION): %.$(CXX_SOURCE_EXTENSION)

# Clean everything except the programs.
mostlyclean:
	$(QUIET) rm -f $(CXX_PRECOMPILED_HEADERS) $(CXX_OBJECTS) $(CONVLIB_FILE) $(SHAREDLIB_FILE)

# Remove everything Make created.
clean: mostlyclean
	$(QUIET) rm -f $(CXX_PROGS) includes.txt

# Even if a file 'clean' exists, 'make clean' keeps working.
.PHONY: all clean mostlyclean test help check analyze submit

# Build everything strictly.
# On macOS/Clang this is just a strict-warnings build.
# On Linux/GCC this also enables -fanalyzer.
ifeq ($(CXX_IS_CLANG),yes)

pedantic: CXXFLAGS += $(PEDANTICFLAGS) -O1 -g
pedantic: clean all
	@echo "Built with pedantic warnings (Clang)."

# Clang's static analyzer. Runs a separate analysis pass over all sources.
analyze: CXXFLAGS += $(PEDANTICFLAGS) -O1 -g
analyze: clean
	@echo "Running Clang static analyzer on all sources..."
	@$(MAKE) CPPFLAGS="--analyze -Xanalyzer -analyzer-output=text $(CPPFLAGS)" all || true

else

pedantic: CXXFLAGS += $(PEDANTICFLAGS) -O1 -g
pedantic: clean all
	@echo "Built with pedantic and extra analyzer warnings (GCC)."

analyze: pedantic

endif


%_tested: %
	@echo -n "Running $< ... "
	@$(<)
	@echo ok

check: all $(patsubst %,%_tested,$(CXX_TESTPROGS))

# Don't create unless needed:
.INTERMEDIATE: $(CXX_OBJECTS) $(CXX_PRECOMPILED_HEADERS)

# Once created, don't delete unless by make clean.
.SECONDARY: $(CXX_PRECOMPILED_HEADERS) $(CXX_OBJECTS)

# Any files created by failed recipes should be deleted.
.DELETE_ON_ERROR:


# If asked explicitly, we can make a metadata.txt... maybe.
ifneq (,$(filter %metadata.txt,$(MAKECMDGOALS)))

    # The requested metadata.txt with full path.
    METADATA_TXT = $(filter %metadata.txt,$(MAKECMDGOALS))

    # Only create metadata.txt here or in parent.
    #$(or $(filter metadata.txt,$(METADATA_TXT)),$(filter ../metadata.txt,$(METADATA_TXT)),$(error Will only create metadata.txt in current or parent directory, and nowhere else.))

    $(METADATA_TXT): TEMPLATE = $(METADATA_TXT_TEMPLATE)
    $(METADATA_TXT):
	$(QUIET) printf '$(subst $(NEWLINE),\n,$(TEMPLATE))' >> "$(@)"
	@echo "$(@) made from template:"
	@echo
	@cat $@
	@echo
	@echo "Please edit it to replace the bogus information in there."
	@echo
	@echo "The metadata.txt tells us what set this is, who worked on the exercises, and who should rate them."
	@echo "Change at least the set number and the authors."
	@echo "If this is your first submission, leave the rater blank."
	@echo "If it is the second, specify the initials of whoever rated the first attempt."

endif

# If asked explicitly, we can make an initial order.txt.
ifneq (,$(filter %order.txt,$(MAKECMDGOALS)))

    ORDER_TXTS = $(filter %order.txt,$(MAKECMDGOALS))

    $(ORDER_TXTS): TEMPLATE = $(ORDER_TXT_TEMPLATE)
    $(ORDER_TXTS): %order.txt: clean
	$(QUIET) printf '$(subst $(NEWLINE),\n,$(TEMPLATE))' >> $(@)
	@echo "$(@) made from template:"
	@echo
	@cat $@
	@echo
	@echo "Please edit it, because an auto-generated one is almost certainly wrong."
	@echo "A '-' prefix means the file should be in the zip, but should not be shown."
	@echo "Per class we prefer header files, then internal headers, then sources."
	@echo "Per project we prefer calling order."
	@echo
	@echo "Please do not submit executables and other binaries."
	@echo "You may therefore want to make clean before making order.txt."

endif

# If we're in a set directory, and if asked explicitly, we can create a zip.
ifneq (,$(filter zip,$(MAKECMDGOALS)))

    ZIPFILE = $(notdir $(CURDIR)).zip
    METADATAS = $(filter %metadata.txt,$(ALL_FILES))

    ifeq (0,$(words $(METADATAS)))
        # No metadata.txt found.
        ifeq (../metadata.txt,$(wildcard ../metadata.txt))
            $(info You asked for a zip, but there is no metadata.txt in the tree.)
            $(info However, there is one in the parent directory.)
            $(info Assuming that we are in an exercise directory and the parent directory)
            $(info contains the set, you can still create the zip.)
            $(info Tell make to switch directories and still use the current makefile)
            $(info with the command:)
            $(info     make -C .. -f $(notdir $(CURDIR))/$(notdir $(CURRENT_MAKEFILE)) zip)
            $(error No metadata.txt in current dir. Perhaps we are not in a set directory.)
        else
            $(info No metadata.txt found in the tree, nor in the parent dir.)
            $(info Depending on whether we are in a set or an exercise directory, you can)
            $(info 'make metadata.txt' or 'make ../metadata.txt' and edit the example.)
            $(error No metadata.txt found.)
        endif
    else
    ifeq (1,$(words $(METADATAS)))
        # One metadata.txt found.
        ifneq (metadata.txt,$(filter metadata.txt,$(METADATAS)))
            $(info A metadata.txt was found: $(METADATAS))
            $(info but it is in a subdir.)
            $(info We need to be in the top-level directory of the exercise set to create the zip.)
            $(error Metadata.txt in unexpected directory.)
        endif
            # This is good: metadata.txt found in current dir.
    else
        # Multiple metadata.txts found.
        ifeq (metadata.txt,$(filter metadata.txt,$(METADATAS)))
            $(warn Multiple metadata.txt files found: $(METADATAS))
            $(info There is one in the current directory.)
            $(info Proceeding anyway on the assumption we are in a set directory.)
        else
            $(info Multiple metadata.txt files found in the tree, but none in the current directory.)
            $(info We have no idea how to handle this.)
            $(error Multiple metadata.txt but not in the right place.)
        endif
    endif
    endif

    DIRECT_SUBDIRS = $(patsubst %/,%,$(filter-out generated_deps/,$(wildcard */)))
    NUMERIC_DIRECT_SUBDIRS = $(shell echo $(DIRECT_SUBDIRS)|grep -Eo '[0-9]{1,2}')

    ifneq ($(DIRECT_SUBDIRS),$(NUMERIC_DIRECT_SUBDIRS))

    $(info You asked for a zip. Assuming we are in a set directory,)
    $(info the exercises should be in the top-level subdirs, and we found these:)
    $(info $(DIRECT_SUBDIRS))
    $(info However, exercise dirs should have numerical names, and not all of them do.)
    $(info (Please note that any 'generated_deps' is not the problem.))
    $(error Other than exercise dirs present. (Perhaps we are not in a set dir.))

    endif

    # Zip is simply an alias for the zipfile.
    zip: $(ZIPFILE)

    # Require 'all' to check that everything compiles.
    $(ZIPFILE): metadatatxt_check build_check ordertxt_check
	echo "To be done: create $(@)"
	zip $(ZIPFLAGS)  $(ZIPFILE) $(ORDER_TXTS) $(FILES_MENTIONED_IN_ORDER_TXTS) metadata.txt x "*/.*" -x "__MACOSX"

    .PHONY: metadatatxt_check build_check ordertxt_check

    # Here's why we only create zips from the set dir.
    # If something doesn't compile, we don't build the zip.
    build_check: all
	@echo "Exercises are buildable."

    # Every subdir must have an order.txt.
    # Every file in an order.txt must contain only file names that exist.
    ORDER_TXTS = $(patsubst %,%/order.txt,$(DIRECT_SUBDIRS))
    FILES_MENTIONED_IN_ORDER_TXTS = $(foreach OTXT,$(ORDER_TXTS),$(foreach LINE,$(patsubst -%,%,$(filter-out -,$(shell cat $(OTXT)))),$(dir $(OTXT))$(LINE)))
    ordertxt_check: $(FILES_MENTIONED_IN_ORDER_TXTS)
	@echo "Files mentioned in order.txt files exist."

    metadatatxt_check:
	@if grep -q "John Doe" metadata.txt || grep -q 'Set 0' metadata.txt ; then echo "metadata.txt still contains bogus info." ; false ; fi
	@echo "metadata.txt exists and was edited."

endif

help:
	@printf '$(subst $(NEWLINE),\n,$(HELP_TEXT))'

# Give Make no way to make hooks.mk. User has to create it.
hooks.mk:


# ============================================================================
# make submit
# ----------------------------------------------------------------------------
# Creates metadata.txt (if absent) from the current directory name, and
# generates order.txt in each exercise subdirectory (if absent).
# Everything runs in a single shell so the helper functions work naturally.
# ============================================================================

SHELL := /bin/bash
.ONESHELL:
.SILENT submit:


submit:
	@echo "creating metadata"
	create_metadata() { 
	    [ -f "metadata.txt" ] && return 0 
	    local dir_name number 
	    dir_name=$$(basename "$$PWD") 
	    number="$${dir_name#week}" 
	    { 
	        echo "Set: Set $$number" 
	        echo "Authors: Riccardo Carlini, Cillian O'Halloran" 
	        echo "Rater:" 
	    } > metadata.txt 
	    echo "Created metadata.txt:" 
	    cat metadata.txt
	}

	create_metadata

	echo
	echo "Ensuring each exercise directory has a preamble.txt and an order.txt."

	for d in */; do
	    [ -d "$$d" ] || continue
	    (
	        cd "$$d" && echo "$$d"

	        # --- preamble.txt -------------------------------------------
	        if [ ! -f "preamble.txt" ]; then
	            echo "Please summarise exercise $$d"
	            echo "(finish with Ctrl-D; empty input deletes the file)"
	            if cat > preamble.txt; then
	                [ -s preamble.txt ] || rm -f preamble.txt
	            else
	                rm -f preamble.txt
	            fi
	        fi

	        # --- order.txt ----------------------------------------------
	        list_dir() {
	            local dir="$$1"
	            local p=""
	            [ "$$dir" != "." ] && p="$$dir/"
	            (
	                cd "$$dir" 2>/dev/null && {
	                    {
	                        ls *.hh 2>/dev/null
	                        ls *.ih 2>/dev/null
	                        ls *.cc 2>/dev/null | grep -v '^main.cc$$'
	                    } | awk -v prefix="$$p" '{print prefix $$0}'
	                }
	            )
	        }

	        if [ ! -f "order.txt" ]; then
	            {
	                ls *.txt 2>/dev/null | grep -v '^order.txt$$'
	                for sub in */; do
	                    [ -d "$$sub" ] && list_dir "$${sub%/}"
	                done
	                list_dir "."
	                echo "main.cc"
	            } > order.txt
	            echo "Wrote $$d/order.txt"
	        else
	            echo "Kept existing $$d/order.txt"
	        fi

	    )
	done

	echo
	echo "Done. Review metadata.txt and each order.txt, then run 'make zip'."


###  Below follow some templates that will create source and header files. ###

# The program source template shares its suffix with other sources.
# So we use this trick: 'make foo.cc:program' will create a program 'foo.cc'.

# Add proper extension if there was none, and remove e.g. ':program'.
ACTUAL_FILE = $(addsuffix .$(EXTENSION),$(patsubst %.$(EXTENSION),%,$*))

%\:program: TEMPLATE = $(CXX_PROGRAM_TEMPLATE)
%\:program: EXTENSION = $(CXX_SOURCE_EXTENSION)

%\:program:
	$(QUIET) if test -e "$(ACTUAL_FILE)" ; then echo "$(ACTUAL_FILE) already exists." ; false ; fi
	$(QUIET) printf '$(subst $(NEWLINE),\n,$(TEMPLATE))' >> "$(ACTUAL_FILE)" && echo "$(ACTUAL_FILE) made from template"

# Not used. Using just extensions is shorter.
#%\:cxx_class: %\:cxx_header %\:cxx_internal_header

# Only files that are explictly mentioned on the command line and that don't
#exist yet, can be created. Use like: make bar.hh

# Header template. We use a UUID to keep the header guard unique.
define CXX_HEADER_TEMPLATE
#ifndef def_$(UUID)_$(HID)_$(CXX_HEADER_EXTENSION)
#define def_$(UUID)_$(HID)_$(CXX_HEADER_EXTENSION)
#endif //def_$(UUID)_$(HID)_$(CXX_HEADER_EXTENSION)\n
endef


# To detect (internal) headers that already exist in the dir.
include-headers-in-same-dir = $(foreach HEADER,$(wildcard $(@D)/*.$(CXX_HEADER_EXTENSION)),#include "$(notdir $(HEADER))"\n)
include-internal-headers-in-same-dir = $(foreach IHEADER,$(wildcard $(@D)/*.$(CXX_INTERNAL_HEADER_EXTENSION)),#include "$(notdir $(IHEADER))"\n)

# Internal header template.
define CXX_INTERNAL_HEADER_TEMPLATE
$(include-headers-in-same-dir)

using namespace std;\n
endef

# # Ordinary source template
# define C
