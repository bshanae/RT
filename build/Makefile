#	#################################################################	#
#	COLORS																#
#	#################################################################	#

COLOR_RED = \033[0;31m
COLOR_NONE = \033[0m

#	#################################################################	#
#	MATH																#
#	#################################################################	#

define MATH_ADD
${shell echo $1+$2 | bc}
endef

define MATH_MULTIPLY
${shell echo $1*$2 | bc}
endef

define MATH_DIVIDE
${shell echo $1/$2 | bc}
endef

define MATH_INCR
${eval $1 = ${call MATH_ADD,${$1},1}}
endef

define MATH_PERCENT
${call MATH_DIVIDE,${call MATH_MULTIPLY,$1,100},$2}
endef

#	#################################################################	#
#	ABSTRACT FUNCTIONS													#
#	#################################################################	#

define FUNC_CALL_VOID
${eval ${call $1}}
endef

define FUNC_READ_DATA
${shell grep -v '^\#' $1}
endef

define FUNC_ITERATE
${foreach line, $2, ${call $1, ${line}}}
endef

define FUNC_READ_FIELD
${shell grep '^${2}' $1 | awk '{$$1= ""; print $$0}'}
endef

#	#################################################################	#
#	INCLUDES FUNCTIONS													#
#	#################################################################	#

define FUNC_GENERATE_INCLUDE
${addprefix -I, $1}
endef

define FUNC_LOAD_INCLUDES
${eval VAR_INCLUDES_DATA = ${call										\
	FUNC_READ_DATA, ${VAR_INCLUDES_LIST}}}
${eval VAR_INCLUDES = ${call											\
	FUNC_ITERATE, FUNC_GENERATE_INCLUDE, ${VAR_INCLUDES_DATA}}}
endef

#	#################################################################	#
#	LINKS FUNCTIONS														#
#	#################################################################	#

define FUNC_GENERATE_LINK_DIR
${addprefix -L, $1}
endef

define FUNC_GENERATE_LINK_LIB
${addprefix -l, $1}
endef

define FUNC_LOAD_LINKS
${eval VAR_LINKS_DIRS_DATA = ${call										\
	FUNC_READ_DATA, ${VAR_LINKS_DIRS_LIST}}}
${eval VAR_LINKS_LIBS_DATA = ${call										\
	FUNC_READ_DATA, ${VAR_LINKS_LIBS_LIST}}}
${eval VAR_LINKS_DIRS = ${call											\
	FUNC_ITERATE, FUNC_GENERATE_LINK_DIR, ${VAR_LINKS_DIRS_DATA}}}
${eval VAR_LINKS_LIBS = ${call											\
	FUNC_ITERATE, FUNC_GENERATE_LINK_LIB, ${VAR_LINKS_LIBS_DATA}}}
endef

#	#################################################################	#
#	SOURCES FUNCTIONS													#
#	#################################################################	#

define FUNC_GENERATE_SOURCE
${notdir $1}
endef

define FUNC_LOAD_SOURCES
${eval VAR_SOURCES_DATA = ${call FUNC_READ_DATA, ${VAR_SOURCES_LIST}}}
${eval VAR_SOURCES = ${call												\
	FUNC_ITERATE, FUNC_GENERATE_SOURCE, ${VAR_SOURCES_DATA}}}
endef

#	#################################################################	#
#	OBJECTS FUNCTIONS													#
#	#################################################################	#

define FUNC_GENERATE_OBJECT
${patsubst %.c, %.o, ${addprefix ${VAR_OBJECTS_FOLDER}/, ${notdir $1}}}
endef

define FUNC_GENERATE_OBJECT_TEMP
${patsubst %.c, %.o, ${notdir $1}}
endef

define FUNC_LOAD_OBJECTS
${eval VAR_OBJECTS = ${call FUNC_ITERATE,								\
	FUNC_GENERATE_OBJECT, ${VAR_SOURCES_DATA}}}
endef

#	#################################################################	#
#	DEPENDENCIES FUNCTIONS												#
#	#################################################################	#

define FUNC_GENERATE_DEPEND
${patsubst %.c, %.d, ${addprefix ${VAR_DEPENDS_FOLDER}/, ${notdir $1}}}
endef

define FUNC_GENERATE_DEPEND_TEMP
${patsubst %.c, %.d, ${notdir $1}}
endef

define FUNC_LOAD_DEPENDS
${eval VAR_DEPENDS = ${call FUNC_ITERATE,								\
	FUNC_GENERATE_DEPEND, ${VAR_SOURCES_DATA}}}
endef


#	#################################################################	#
#	VPATH FUNCTIONS														#
#	#################################################################	#

define FUNC_ADD_VPATH
${if ${findstring ${dir $1} ,${VPATH}},,${eval VPATH += ${dir $1}}}	
endef

define FUNC_ADD_VPATH_ALL
${foreach																\
	line,																\
	$1,																	\
	${call FUNC_ADD_VPATH, ${line}}										\
}
endef

define FUNC_LOAD_VPATH
${call FUNC_ADD_VPATH_ALL,${VAR_SOURCES_DATA}}
endef

#	#################################################################	#
#	PROJECT FUNCTIONS													#
#	#################################################################	#

define FUNC_LOAD_PROJECT
${eval VAR_PROJECT_EXE = ${call FUNC_READ_FIELD,						\
	${VAR_PROJECT_LIST},${VAR_PROJECT_EXE_MASK}}}
${eval VAR_PROJECT_FLAGS_OBJECT = ${call FUNC_READ_FIELD,				\
	${VAR_PROJECT_LIST},${VAR_PROJECT_FLAGS_OBJECT_MASK}}}
${eval VAR_PROJECT_FLAGS_EXE = ${call FUNC_READ_FIELD,				\
	${VAR_PROJECT_LIST},${VAR_PROJECT_FLAGS_EXE_MASK}}}
endef

#	#################################################################	#
#	COUNT FUNCTIONS														#
#	#################################################################	#

define FUNC_LOAD_COUNT
${eval VAR_COUNT_CURRENT = 0}
${eval VAR_COUNT_TOTAL = ${words ${VAR_SOURCES_DATA}}}
endef

define FUNC_COUNT_OBJECT
@echo "${shell															\
	printf "[%2d%%] Building C object $1" ${VAR_COUNT_PERCENT}}"
${call MATH_INCR,VAR_COUNT_CURRENT}
${eval VAR_COUNT_PERCENT = ${call MATH_PERCENT,							\
	${VAR_COUNT_CURRENT},${VAR_COUNT_TOTAL}}}
endef

define FUNC_COUNT_EXE
@echo "${shell printf "[100%%] Linking C executable $1"}"
endef

#	#################################################################	#
#	COMPILATION FUNCTIONS												#
#	#################################################################	#

define FUNC_COMPILE_OBJECT
${call FUNC_COUNT_OBJECT,$1}
@gcc																	\
	-MMD																\
	-MP																	\
	-MT ${call FUNC_GENERATE_OBJECT, $1}								\
	-MF ${call FUNC_GENERATE_DEPEND, $1}								\
	${VAR_INCLUDES}														\
	${VAR_PROJECT_FLAGS_OBJECT}											\
	-c $1																\
	-o ${call FUNC_GENERATE_OBJECT, $1}
endef

define FUNC_COMPILE_EXE
${call FUNC_COUNT_EXE, ${VAR_PROJECT_EXE}}
@gcc																	\
	${VAR_PROJECT_FLAGS_EXE}											\
	${VAR_INCLUDES}														\
	${VAR_LINKS_DIRS}													\
	${VAR_LINKS_LIBS}													\
	${VAR_OBJECTS}														\
	-o ${VAR_PROJECT_EXE}
endef

#	#################################################################	#
#	VARIABLES															#
#	#################################################################	#

VAR_COUNT_CURRENT =
VAR_COUNT_TOTAL =
VAR_COUNT_PERCENT =
VAR_COUNT_OUT = ./count.txt

VAR_INCLUDES_LIST = ./includes.txt
VAR_INCLUDES_DATA = 
VAR_INCLUDES =

VAR_LINKS_DIRS_LIST = ./links_dirs.txt
VAR_LINKS_DIRS_DATA = 
VAR_LINKS_DIRS = 

VAR_LINKS_LIBS_LIST = ./links_libs.txt
VAR_LINKS_LIBS_DATA = 
VAR_LINKS_LIBS = 

VAR_SOURCES_LIST = ./sources.txt
VAR_SOURCES_DATA = 
VAR_SOURCES =

VAR_OBJECTS_FOLDER = ./objects
VAR_OBJECTS = 

VAR_DEPENDS_FOLDER = ./dependencies
VAR_DEPENDS = 

VAR_PROJECT_LIST = ./project.txt
VAR_PROJECT_PATH = ../

VAR_PROJECT_EXE_MASK = exe
VAR_PROJECT_EXE = 

VAR_PROJECT_FLAGS_OBJECT_MASK = flag_object
VAR_PROJECT_FLAGS_OBJECT =

VAR_PROJECT_FLAGS_EXE_MASK = flag_exe
VAR_PROJECT_FLAGS_EXE =


#	#################################################################	#
#	MAIN																#
#	#################################################################	#

${call FUNC_CALL_VOID, FUNC_LOAD_INCLUDES}
${call FUNC_CALL_VOID, FUNC_LOAD_LINKS}
${call FUNC_CALL_VOID, FUNC_LOAD_SOURCES}
${call FUNC_CALL_VOID, FUNC_LOAD_OBJECTS}
${call FUNC_CALL_VOID, FUNC_LOAD_DEPENDS}
${call FUNC_CALL_VOID, FUNC_LOAD_VPATH}
${call FUNC_CALL_VOID, FUNC_LOAD_PROJECT}
${call FUNC_CALL_VOID, FUNC_LOAD_COUNT}

all : ${VAR_PROJECT_EXE}

test :
	@echo "${COLOR_RED}\c"
	@echo "includes = {${VAR_INCLUDES_DATA}}\n"
	@echo "linked dirs = {${VAR_LINKS_DIRS}}\n"
	@echo "linked libs = {${VAR_LINKS_LIBS}}\n"
	@echo "sources = {${VAR_SOURCES}}\n"
	@echo "objects = {${VAR_OBJECTS}}\n"
	@echo "depends = {${VAR_DEPENDS}}\n"
	@echo "VPATH = {${VPATH}}\n"
	@echo "exe = {${VAR_PROJECT_EXE}}\n"
	@echo "object flags = {${VAR_PROJECT_FLAGS_OBJECT}}\n"
	@echo "exe flags = {${VAR_PROJECT_FLAGS_EXE}}\n"
	@echo "total sources = ${VAR_COUNT_TOTAL}\n"
	@echo "${COLOR_NONE}\c"

${VAR_OBJECTS_FOLDER} :
	@mkdir ${VAR_OBJECTS_FOLDER}
	@echo "Creating folder for objects"

${VAR_OBJECTS_FOLDER}/%.o : %.c											\
							${VAR_DEPENDS_FOLDER}/%.d					\
							${VAR_PROJECT_LIST}							\
							${VAR_INCLUDES_LIST}						\
							${VAR_LINKS_DIRS_LIST}						\
							${VAR_LINKS_LIBS_LIST}						\
							|											\
							${VAR_OBJECTS_FOLDER}						\
							${VAR_DEPENDS_FOLDER}
	${call FUNC_COMPILE_OBJECT,$<}

${VAR_DEPENDS_FOLDER} :
	@mkdir ${VAR_DEPENDS_FOLDER}
	@echo "Creating folder for dependencies"

${VAR_DEPENDS} :

include ${wildcard ${VAR_DEPENDS}}

${VAR_PROJECT_EXE} : ${VAR_OBJECTS}
	${call FUNC_COMPILE_EXE}

clean :
	@echo "Deleting objects"
	@rm -rf ${VAR_OBJECTS_FOLDER}
	@echo "Deleting dependencies"
	@rm -rf ${VAR_DEPENDS_FOLDER}

fclean : clean

re : fclean all
