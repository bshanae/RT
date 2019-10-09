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

define FUNC_INFO
${info [RT] : $1}
endef

#	#################################################################	#
#	INCLUDES FUNCTIONS													#
#	#################################################################	#

define FUNC_GENERATE_INCLUDE
${addprefix -I, $1}
endef

define FUNC_LOAD_INCLUDES
${call FUNC_INFO,Loadind includes}
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
${call FUNC_INFO,Loadind links}
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
${call FUNC_INFO,Loadind sources}
${eval VAR_SOURCES_DATA = ${call FUNC_READ_DATA, ${VAR_SOURCES_LIST}}}
${eval VAR_SOURCES = ${call												\
	FUNC_ITERATE, FUNC_GENERATE_SOURCE, ${VAR_SOURCES_DATA}}}
endef

#	#################################################################	#
#	OBJECTS FUNCTIONS													#
#	#################################################################	#

define FUNC_GENERATE_OBJECT
${patsubst %.c,%.o,${addprefix ${VAR_OBJECTS_FOLDER}/, ${notdir $1}}}
endef

define FUNC_GENERATE_OBJECT_TEMP
${patsubst %.c, %.o, ${notdir $1}}
endef

define FUNC_LOAD_OBJECTS
${call FUNC_INFO,Loadind objects}
${eval VAR_OBJECTS = ${call FUNC_ITERATE,								\
	FUNC_GENERATE_OBJECT, ${VAR_SOURCES_DATA}}}
endef

#	#################################################################	#
#	DEPENDENCIES FUNCTIONS												#
#	#################################################################	#

define FUNC_GENERATE_DEPEND
${patsubst %.c,%.d,${addprefix ${VAR_DEPENDS_FOLDER}/, ${notdir $1}}}
endef

define FUNC_GENERATE_DEPEND_TEMP
${patsubst %.c, %.d, ${notdir $1}}
endef

define FUNC_LOAD_DEPENDS
${call FUNC_INFO,Loadind dependencies}
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
${call FUNC_INFO,Loadind paths to sources}
${call FUNC_ADD_VPATH_ALL,${VAR_SOURCES_DATA}}
endef

#	#################################################################	#
#	PROJECT FUNCTIONS													#
#	#################################################################	#

define FUNC_LOAD_PROJECT
${eval VAR_PROJECT_EXE = ${call FUNC_READ_FIELD,						\
	${VAR_PROJECT_LIST},${VAR_PROJECT_EXE_MASK}}}
${eval VAR_PROJECT_FLAGS_ANY += ${call FUNC_READ_FIELD,					\
	${VAR_PROJECT_LIST},${VAR_PROJECT_FLAGS_ANY_MASK}}}
${eval VAR_PROJECT_FLAGS_OBJECT += ${call FUNC_READ_FIELD,				\
	${VAR_PROJECT_LIST},${VAR_PROJECT_FLAGS_OBJECT_MASK}}}
${eval VAR_PROJECT_FLAGS_EXE += ${call FUNC_READ_FIELD,					\
	${VAR_PROJECT_LIST},${VAR_PROJECT_FLAGS_EXE_MASK}}}
${eval VAR_PROJECT_EXTERN_DATA += ${call FUNC_READ_FIELD,				\
	${VAR_PROJECT_LIST},${VAR_PROJECT_EXTERN_MASK}}}
${eval VAR_PROJECT_EXTERN_TARGET = ${word 1, ${VAR_PROJECT_EXTERN_DATA}}}
${eval VAR_PROJECT_EXTERN_DIR = ${word 2, ${VAR_PROJECT_EXTERN_DATA}}}
endef

define FUNC_RUN_EXTERN
${call FUNC_INFO,Loadind extern make}
${if																	\
	${VAR_PROJECT_EXTERN_DATA},											\
	@make $1 -C ${VAR_PROJECT_EXTERN_DIR}						\
	,																	\
}	
endef

#	#################################################################	#
#	TEMP FUNCTIONS														#
#	#################################################################	#

define FUNC_GENERATE_TEMP
${patsubst %.c,%.temp,${addprefix ${VAR_TEMPS_FOLDER}/, ${notdir $1}}}
endef

define FUNC_LOAD_TEMPS
${call FUNC_INFO,Loadind temporary files}
${eval VAR_TEMPS = ${call FUNC_ITERATE,									\
	FUNC_GENERATE_TEMP, ${VAR_SOURCES_DATA}}}
endef

define FUNC_MAKE_TEMP
${call FUNC_INFO,Building temporary file ${call FUNC_GENERATE_TEMP, $1}}
@touch ${call FUNC_GENERATE_TEMP, $1}
endef

#	#################################################################	#
#	COUNT FUNCTIONS														#
#	#################################################################	#

define FUNC_LOAD_COUNT
${call FUNC_INFO,Loadind counter}
${eval VAR_COUNT_CURRENT = 0}
${eval VAR_COUNT_TOTAL = 0}
endef

define FUNC_COUNT_OBJECT
${call FUNC_INFO,${shell													\
	printf "[%3d%%] Building C object $1" ${VAR_COUNT_PERCENT}}}
${call MATH_INCR,VAR_COUNT_CURRENT}
${eval VAR_COUNT_PERCENT = ${call MATH_PERCENT,							\
	${VAR_COUNT_CURRENT},${VAR_COUNT_TOTAL}}}
endef

define FUNC_COUNT_EXE
${call FUNC_INFO,${shell printf "[100%%] Linking C executable $1"}}
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
	${VAR_PROJECT_FLAGS_ANY}											\
	${VAR_PROJECT_FLAGS_OBJECT}											\
	-c $1																\
	-o ${call FUNC_GENERATE_OBJECT, $1}
endef

define FUNC_COMPILE_EXE
${call FUNC_COUNT_EXE, ${VAR_PROJECT_EXE}}
@gcc																	\
	${VAR_PROJECT_FLAGS_ANY}											\
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

VAR_TEMPS_FOLDER = ./temps
VAR_TEMPS = 

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

VAR_PROJECT_TEST = test

VAR_PROJECT_EXE_MASK = exe
VAR_PROJECT_EXE =

VAR_PROJECT_FLAGS_ANY_MASK = flag_any
VAR_PROJECT_FLAGS_ANY =

VAR_PROJECT_FLAGS_OBJECT_MASK = flag_object
VAR_PROJECT_FLAGS_OBJECT =

VAR_PROJECT_FLAGS_EXE_MASK = flag_exe
VAR_PROJECT_FLAGS_EXE =

VAR_PROJECT_EXTERN_MASK = extern
VAR_PROJECT_EXTERN_DATA = 
VAR_PROJECT_EXTERN_TARGET =
VAR_PROJECT_EXTERN_DIR = 

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
${call FUNC_CALL_VOID, FUNC_LOAD_TEMPS}
${call FUNC_CALL_VOID, FUNC_LOAD_COUNT}

.PHONY : all report clean clean_no_extern fclean fclean_no_extern re re_no_extern

all : ${VAR_PROJECT_TEST}

report : ${VAR_TEMPS}
	@echo "${COLOR_RED}\c"
	@echo "includes = {${VAR_INCLUDES_DATA}}\n"
	@echo "linked dirs = {${VAR_LINKS_DIRS}}\n"
	@echo "linked libs = {${VAR_LINKS_LIBS}}\n"
	@echo "sources = {${VAR_SOURCES}}\n"
	@echo "objects = {${VAR_OBJECTS}}\n"
	@echo "depends = {${VAR_DEPENDS}}\n"
	@echo "VPATH = {${VPATH}}\n"
	@echo "exe = {${VAR_PROJECT_EXE}}\n"
	@echo "any flags = {${VAR_PROJECT_FLAGS_ANY}}\n"
	@echo "object flags = {${VAR_PROJECT_FLAGS_OBJECT}}\n"
	@echo "exe flags = {${VAR_PROJECT_FLAGS_EXE}}\n"
	@echo "extern = {${VAR_PROJECT_EXTERN_TARGET}, ${VAR_PROJECT_EXTERN_DIR}}\n"
	@echo "temps = {${VAR_TEMPS}}\n"
	@echo "total sources = ${VAR_COUNT_TOTAL}\n"
	@echo "${COLOR_NONE}\c"

${VAR_TEMPS_FOLDER} :
	${call FUNC_INFO,Creating folder for temporary files}
	@mkdir ${VAR_TEMPS_FOLDER}


${VAR_OBJECTS_FOLDER} :
	${call FUNC_INFO,Creating folder for objects}
	@mkdir ${VAR_OBJECTS_FOLDER}

${VAR_DEPENDS_FOLDER} :
	@mkdir ${VAR_DEPENDS_FOLDER}
	${call FUNC_INFO,Creating folder for dependencies}


${VAR_TEMPS_FOLDER}/%.temp : %.c										\
							${VAR_DEPENDS_FOLDER}/%.d					\
							${VAR_PROJECT_LIST}							\
							${VAR_INCLUDES_LIST}						\
							${VAR_LINKS_DIRS_LIST}						\
							${VAR_LINKS_LIBS_LIST}						\
							|											\
							${VAR_TEMPS_FOLDER}
	${call FUNC_MAKE_TEMP,$<}
	${call MATH_INCR,VAR_COUNT_TOTAL}

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

${VAR_DEPENDS} :

include ${wildcard ${VAR_DEPENDS}}

${VAR_PROJECT_EXTERN_TARGET} :
	${call FUNC_RUN_EXTERN,try}

${VAR_PROJECT_EXE} : ${VAR_PROJECT_EXTERN_TARGET} ${VAR_TEMPS} ${VAR_OBJECTS}
	${call FUNC_COMPILE_EXE}

${VAR_PROJECT_TEST} : ${VAR_PROJECT_EXE}
	@touch ${VAR_PROJECT_TEST}
	@rm ${VAR_PROJECT_TEST}

clean :
	${call FUNC_INFO,Cleaning extern}
	${call FUNC_RUN_EXTERN,clean}
	@rm -rf ${VAR_TEMPS_FOLDER}
	${call FUNC_INFO,Deleting temporary files}
	${call FUNC_INFO,Deleting objects}
	@rm -rf ${VAR_OBJECTS_FOLDER}
	${call FUNC_INFO,Deleting dependencies}
	@rm -rf ${VAR_DEPENDS_FOLDER}

clean_no_extern :
	@rm -rf ${VAR_TEMPS_FOLDER}
	${call FUNC_INFO,Deleting temporary files}
	${call FUNC_INFO,Deleting objects}
	@rm -rf ${VAR_OBJECTS_FOLDER}
	${call FUNC_INFO,Deleting dependencies}
	@rm -rf ${VAR_DEPENDS_FOLDER}

fclean : clean_no_extern
	${call FUNC_INFO,Deleting exe}
	@rm -f ${VAR_PROJECT_EXE}
	${call FUNC_INFO,Cleaning extern}
	${call FUNC_RUN_EXTERN,fclean}


fclean_no_extern : clean_no_extern
	${call FUNC_INFO,Deleting exe}
	@rm -f ${VAR_PROJECT_EXE}

re : fclean_no_extern
	${call FUNC_RUN_EXTERN,re}
	@make ${VAR_PROJECT_EXE}

re_no_extern : fclean_no_extern
	@make ${VAR_PROJECT_EXE}
