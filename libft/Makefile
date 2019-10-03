FUNC_INFO = ${info [Libft] : $1}
FUNC_ITERATE = ${foreach line,$2,${call $1,${line}}}

INCLUDES = -I ./includes

SOURCES_DIR = ./sources
SOURCES_LIST = ./sources_list.txt
SOURCES = ${shell cat ${SOURCES_LIST}}

FUNC_GEN_OBJECT = ${patsubst %.c,%.o,${addprefix ${OBJECTS_DIR}/,${notdir $1}}}
OBJECTS_DIR = ./objects
OBJECTS = ${call FUNC_ITERATE,FUNC_GEN_OBJECT,${SOURCES}}

FUNC_GEN_DEPEND = ${patsubst %.c,%.d,${addprefix ${DEPENDS_DIR}/,${notdir $1}}}
DEPENDS_DIR = ./depends
DEPENDS = ${call FUNC_ITERATE,FUNC_GEN_DEPEND,${SOURCES}}

LIB = libft.a
TRY = try

all : ${LIB}

${TRY} : all
	@touch ${TRY}
	@rm ${TRY}


${LIB} : ${OBJECTS} ${DEPENDS} | ${OBJECTS_DIR} ${DEPENDS_DIR}
	${call FUNC_INFO,Building library}
	@ar rc ${LIB} ${OBJECTS}
	@ranlib ${LIB}

${OBJECTS_DIR} :
	${call FUNC_INFO,Creating folder for objects}
	@mkdir ${OBJECTS_DIR}

${OBJECTS_DIR}/%.o : ${SOURCES_DIR}/%.c ${DEPENDS_DIR}/%.d | ${OBJECTS_DIR} ${DEPENDS_DIR}
	${call FUNC_INFO,Compiling C object $<}
	@gcc -MMD -MT $@ -MF ${call FUNC_GEN_DEPEND,$<} ${INCLUDES} -c $< -o $@

${DEPENDS_DIR} :
	${call FUNC_INFO,Creating folder for depends}
	@mkdir ${DEPENDS_DIR}

${DEPENDS} :

clean :
	${call FUNC_INFO,Deleting objects}
	@rm -rf ${OBJECTS_DIR}
	${call FUNC_INFO,Deleting depends}
	@rm -rf ${DEPENDS_DIR}

fclean : clean
	${call FUNC_INFO,Deleting library}
	@rm -rf ${LIB}

re : fclean all

report :
	@echo "sources = {${SOURCES}}\n"
	@echo "objects = {${OBJECTS}}\n"
	@echo "depedns = {${DEPENDS}}\n"

.PHONY : all clean fclean re report

include ${wildcard ${DEPENDS}}
