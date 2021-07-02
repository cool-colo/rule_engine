ROOT=.
DEPS_DIR=$(ROOT)/antlr/runtime
EXAMPLE_DIR=$(ROOT)/examples

BUILDPATHROOT=./build

CC=gcc
CXX=g++

# Modules
MODULE=example
SELECTOR=map_vector

#######################GCC MACROS####################
# STREAM_SYNC = stream sync
# 输出函数ymsg 调用
# PRINT_BACKSTRACE = print backstrace
# 使用TCMALLOC
# TCMALLOC = tcmalloc
# 支持GLOG
# GLOG = use glog
# use boost
# BOOST = use boost

LDFLAGS=
CXXFLAGS=-ggdb \
		 -pipe \
		 -W \
		 -Wall \
		 -fPIC \
		 -Wextra \
		 -Wl,--whole-archive -lpthread -Wl,--no-whole-archive \
		 -m64 \
		 -std=c++20 \
		 -fno-strict-aliasing \
		 -Wno-invalid-offsetof \
		 -Wno-deprecated \
		 -Wno-deprecated-declarations \
		 -Wno-unused-parameter \
		 -Wno-unused-function \
		 -Wno-sign-compare \
		 -Wno-write-strings \
		 -Wno-unused-local-typedefs \
		 -Wno-narrowing \
		 -Wno-parentheses \
		 -Wno-unused-variable \
		 -static \
		 -Wno-char-subscripts \
		 -D__STDC_LIMIT_MACROS \

INC_DIR=-I. \
		-I./third_party/antlr/include/antlr4-runtime \
		-I./third_party/rttr/include \
		-I$(ROOT) \
		-I$(ROOT)/antlr/grammar \
		-I$(ROOT)/antlr/grammar/generated \
		-I$(ROOT)/ast_processor \
		-I$(ROOT)/engine \
		-I$(ROOT)/log
		#-I$(DEPS_DIR) \
		-I$(DEPS_DIR)/atn \
		-I$(DEPS_DIR)/dfa \
		-I$(DEPS_DIR)/misc \
		-I$(DEPS_DIR)/support \

LIB_DIR=       -L./third_party/antlr/lib \
	       -L./third_party/rttr/lib

LIB_INC= -lantlr4-runtime -lrttr_core


###################SYSTEM CHECK####################

######################STRACE########################
ifdef PRINT_BACKSTRACE
CXXFLAGS += -rdynamic -DPRINT_BACKSTRACE
endif

#########################STAT########################

all: PRE_BUILD $(BUILDPATHROOT)/$(MODULE) $(BUILDPATHROOT)/$(SELECTOR)
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40mall[0m']"
	@echo "make all done"


clean:
	@find . -name "*.o" | xargs -I {} rm {}
	@rm -rf $(BUILDPATHROOT)
.phony:clean

OBJS += $(patsubst %.cpp,%.o, $(shell find antlr/grammar -name "*.cpp" | egrep -v "examples/example.cpp" | egrep -v "examples/map_vector.cpp"))
OBJS += ./ast_processor/then_expression.cpp


%.o:%.cpp
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40m$<[0m']"
	$(CXX) $(CXXFLAGS) $(INC_DIR) $(LIB_DIR) -c $< -o $@

%.o:%.cc
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40m$<[0m']"
	$(CXX) $(CXXFLAGS) $(INC_DIR) $(LIB_DIR) -c $< -o $@

%.o:%.c
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40m$<[0m']"
	$(CXX) $(CXXFLAGS) $(INC_DIR) $(LIB_DIR) -c $< -o $@


$(BUILDPATHROOT)/$(MODULE) : $(OBJS) 
	$(CXX) -v -o $@ $(INC_DIR) $(LIB_DIR) $(LDFLAGS) $(CXXFLAGS) \
		$(EXAMPLE_DIR)/example.cpp $(OBJS) $(LIB_INC)

$(BUILDPATHROOT)/$(SELECTOR) : $(OBJS) 
	$(CXX) -v -o $@ $(INC_DIR) $(LIB_DIR) $(LDFLAGS) $(CXXFLAGS) \
		$(EXAMPLE_DIR)/map_vector.cpp $(OBJS) $(LIB_INC)

PRE_BUILD:
	@mkdir -p $(BUILDPATHROOT)


