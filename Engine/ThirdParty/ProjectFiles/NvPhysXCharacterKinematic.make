# Alternative GNU Make project makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

.PHONY: clean prebuild

SHELLTYPE := posix
ifeq (.exe,$(findstring .exe,$(ComSpec)))
	SHELLTYPE := msdos
endif

# Configurations
# #############################################

RESCOMP = windres
INCLUDES += -I../nvphysx/physx/include -I../nvphysx/physx/source/common/include -I../nvphysx/physx/source/common/src -I../nvphysx/physx/source/geomutils/include -I../nvphysx/physx/source/geomutils/src -I../nvphysx/physx/source/geomutils/src/contact -I../nvphysx/physx/source/geomutils/src/common -I../nvphysx/physx/source/geomutils/src/convex -I../nvphysx/physx/source/geomutils/src/distance -I../nvphysx/physx/source/geomutils/src/gjk -I../nvphysx/physx/source/geomutils/src/intersection -I../nvphysx/physx/source/geomutils/src/mesh -I../nvphysx/physx/source/geomutils/src/hf -I../nvphysx/physx/source/geomutils/src/pcm -I../nvphysx/physx/source/foundation/include
FORCE_INCLUDE +=
ALL_CPPFLAGS += $(CPPFLAGS) -MD -MP $(DEFINES) $(INCLUDES)
ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
LINKCMD = $(AR) -rcs "$@" $(OBJECTS)
define PREBUILDCMDS
endef
define PRELINKCMDS
endef
define POSTBUILDCMDS
endef

ifeq ($(config),debug)
TARGETDIR = ../../Build/VS2022/Debug/Binaries/ThirdParty
TARGET = $(TARGETDIR)/NvPhysXCharacterKinematic.lib
OBJDIR = ../../Build/VS2022/Debug/Objs/ThirdParty/NvPhysXCharacterKinematic
DEFINES += -DWIN32 -DWIN64 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -D_WINSOCK_DEPRECATED_NO_WARNINGS -DPX_PHYSX_GPU_SHARED_LIB_NAME=PhysXGpu_64.dll -DPX_PHYSX_STATIC_LIB -DPX_SUPPORT_PVD=1 -DPX_DEBUG=1 -DPX_CHECKED=1 -DPX_NVTX=0 -D_DEBUG
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64 -O0 -g
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -O0 -g -std=c++17
LIBS += ../../Build/VS2022/Debug/Binaries/ThirdParty/NvPhysXFoundation.lib
LDDEPS += ../../Build/VS2022/Debug/Binaries/ThirdParty/NvPhysXFoundation.lib
ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -m64

else ifeq ($(config),release)
TARGETDIR = ../../Build/VS2022/Release/Binaries/ThirdParty
TARGET = $(TARGETDIR)/NvPhysXCharacterKinematic.lib
OBJDIR = ../../Build/VS2022/Release/Objs/ThirdParty/NvPhysXCharacterKinematic
DEFINES += -DWIN32 -DWIN64 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -D_WINSOCK_DEPRECATED_NO_WARNINGS -DPX_PHYSX_GPU_SHARED_LIB_NAME=PhysXGpu_64.dll -DPX_PHYSX_STATIC_LIB -DPX_SUPPORT_PVD=1 -D_HAS_ITERATOR_DEBUGGING=0 -D_ITERATOR_DEBUG_LEVEL=0 -DPX_CHECKED=1 -DPX_NVTX=0 -DNDEBUG
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64 -O2 -g
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -O2 -g -std=c++17
LIBS += ../../Build/VS2022/Release/Binaries/ThirdParty/NvPhysXFoundation.lib
LDDEPS += ../../Build/VS2022/Release/Binaries/ThirdParty/NvPhysXFoundation.lib
ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -m64

else ifeq ($(config),dist)
TARGETDIR = ../../Build/VS2022/Dist/Binaries/ThirdParty
TARGET = $(TARGETDIR)/NvPhysXCharacterKinematic.lib
OBJDIR = ../../Build/VS2022/Dist/Objs/ThirdParty/NvPhysXCharacterKinematic
DEFINES += -DWIN32 -DWIN64 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -D_WINSOCK_DEPRECATED_NO_WARNINGS -DPX_PHYSX_GPU_SHARED_LIB_NAME=PhysXGpu_64.dll -DPX_PHYSX_STATIC_LIB -DPX_SUPPORT_PVD=1 -D_HAS_ITERATOR_DEBUGGING=0 -D_ITERATOR_DEBUG_LEVEL=0 -DPX_CHECKED=1 -DNDEBUG
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64 -O2
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -O2 -std=c++17
LIBS += ../../Build/VS2022/Dist/Binaries/ThirdParty/NvPhysXFoundation.lib
LDDEPS += ../../Build/VS2022/Dist/Binaries/ThirdParty/NvPhysXFoundation.lib
ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -m64 -s

endif

# Per File Configurations
# #############################################


# File sets
# #############################################

GENERATED :=
OBJECTS :=

GENERATED += $(OBJDIR)/CctBoxController.o
GENERATED += $(OBJDIR)/CctCapsuleController.o
GENERATED += $(OBJDIR)/CctCharacterController.o
GENERATED += $(OBJDIR)/CctCharacterControllerCallbacks.o
GENERATED += $(OBJDIR)/CctCharacterControllerManager.o
GENERATED += $(OBJDIR)/CctController.o
GENERATED += $(OBJDIR)/CctObstacleContext.o
GENERATED += $(OBJDIR)/CctSweptBox.o
GENERATED += $(OBJDIR)/CctSweptCapsule.o
GENERATED += $(OBJDIR)/CctSweptVolume.o
OBJECTS += $(OBJDIR)/CctBoxController.o
OBJECTS += $(OBJDIR)/CctCapsuleController.o
OBJECTS += $(OBJDIR)/CctCharacterController.o
OBJECTS += $(OBJDIR)/CctCharacterControllerCallbacks.o
OBJECTS += $(OBJDIR)/CctCharacterControllerManager.o
OBJECTS += $(OBJDIR)/CctController.o
OBJECTS += $(OBJDIR)/CctObstacleContext.o
OBJECTS += $(OBJDIR)/CctSweptBox.o
OBJECTS += $(OBJDIR)/CctSweptCapsule.o
OBJECTS += $(OBJDIR)/CctSweptVolume.o

# Rules
# #############################################

all: $(TARGET)
	@:

$(TARGET): $(GENERATED) $(OBJECTS) $(LDDEPS) | $(TARGETDIR)
	$(PRELINKCMDS)
	@echo Linking NvPhysXCharacterKinematic
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

clean:
	@echo Cleaning NvPhysXCharacterKinematic
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(GENERATED)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(GENERATED)) del /s /q $(subst /,\\,$(GENERATED))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild: | $(OBJDIR)
	$(PREBUILDCMDS)

ifneq (,$(PCH))
$(OBJECTS): $(GCH) | $(PCH_PLACEHOLDER)
$(GCH): $(PCH) | prebuild
	@echo $(notdir $<)
	$(SILENT) $(CXX) -x c++-header $(ALL_CXXFLAGS) -o "$@" -MF "$(@:%.gch=%.d)" -c "$<"
$(PCH_PLACEHOLDER): $(GCH) | $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) touch "$@"
else
	$(SILENT) echo $null >> "$@"
endif
else
$(OBJECTS): | prebuild
endif


# File Rules
# #############################################

$(OBJDIR)/CctBoxController.o: ../nvphysx/physx/source/physxcharacterkinematic/src/CctBoxController.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/CctCapsuleController.o: ../nvphysx/physx/source/physxcharacterkinematic/src/CctCapsuleController.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/CctCharacterController.o: ../nvphysx/physx/source/physxcharacterkinematic/src/CctCharacterController.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/CctCharacterControllerCallbacks.o: ../nvphysx/physx/source/physxcharacterkinematic/src/CctCharacterControllerCallbacks.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/CctCharacterControllerManager.o: ../nvphysx/physx/source/physxcharacterkinematic/src/CctCharacterControllerManager.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/CctController.o: ../nvphysx/physx/source/physxcharacterkinematic/src/CctController.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/CctObstacleContext.o: ../nvphysx/physx/source/physxcharacterkinematic/src/CctObstacleContext.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/CctSweptBox.o: ../nvphysx/physx/source/physxcharacterkinematic/src/CctSweptBox.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/CctSweptCapsule.o: ../nvphysx/physx/source/physxcharacterkinematic/src/CctSweptCapsule.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/CctSweptVolume.o: ../nvphysx/physx/source/physxcharacterkinematic/src/CctSweptVolume.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"

-include $(OBJECTS:%.o=%.d)
ifneq (,$(PCH))
  -include $(PCH_PLACEHOLDER).d
endif