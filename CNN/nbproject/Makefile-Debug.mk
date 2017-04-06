#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/ActRelu.o \
	${OBJECTDIR}/ActSigmoid.o \
	${OBJECTDIR}/Activation.o \
	${OBJECTDIR}/CNN.o \
	${OBJECTDIR}/CNN2.o \
	${OBJECTDIR}/DataPreparation.o \
	${OBJECTDIR}/LayerConvolution.o \
	${OBJECTDIR}/LayerFC.o \
	${OBJECTDIR}/LayerPool.o \
	${OBJECTDIR}/PoolAverage.o \
	${OBJECTDIR}/PoolMax.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cnn

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cnn: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cnn ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/ActRelu.o: ActRelu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/opencv -I/usr/local/include/opencv2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ActRelu.o ActRelu.cpp

${OBJECTDIR}/ActSigmoid.o: ActSigmoid.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/opencv -I/usr/local/include/opencv2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ActSigmoid.o ActSigmoid.cpp

${OBJECTDIR}/Activation.o: Activation.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/opencv -I/usr/local/include/opencv2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Activation.o Activation.cpp

${OBJECTDIR}/CNN.o: CNN.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/opencv -I/usr/local/include/opencv2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CNN.o CNN.cpp

${OBJECTDIR}/CNN2.o: CNN2.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/opencv -I/usr/local/include/opencv2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CNN2.o CNN2.cpp

${OBJECTDIR}/DataPreparation.o: DataPreparation.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/opencv -I/usr/local/include/opencv2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataPreparation.o DataPreparation.cpp

${OBJECTDIR}/LayerConvolution.o: LayerConvolution.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/opencv -I/usr/local/include/opencv2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LayerConvolution.o LayerConvolution.cpp

${OBJECTDIR}/LayerFC.o: LayerFC.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/opencv -I/usr/local/include/opencv2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LayerFC.o LayerFC.cpp

${OBJECTDIR}/LayerPool.o: LayerPool.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/opencv -I/usr/local/include/opencv2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LayerPool.o LayerPool.cpp

${OBJECTDIR}/PoolAverage.o: PoolAverage.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/opencv -I/usr/local/include/opencv2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PoolAverage.o PoolAverage.cpp

${OBJECTDIR}/PoolMax.o: PoolMax.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/opencv -I/usr/local/include/opencv2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PoolMax.o PoolMax.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/opencv -I/usr/local/include/opencv2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
