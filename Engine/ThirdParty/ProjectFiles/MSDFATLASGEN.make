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
DEFINES +=
INCLUDES += -I../MSDFATLASGEN/msdf-atlas-gen -I../MSDFATLASGEN/msdfgen -I../MSDFATLASGEN/msdfgen/include
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
TARGET = $(TARGETDIR)/MSDFATLASGEN.lib
OBJDIR = ../../Build/VS2022/Debug/Objs/ThirdParty/MSDFATLASGEN
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64 -g
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -g -std=c++17
LIBS += ../../Build/VS2022/Debug/Binaries/ThirdParty/MSDFGEN.lib
LDDEPS += ../../Build/VS2022/Debug/Binaries/ThirdParty/MSDFGEN.lib
ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -m64

else ifeq ($(config),release)
TARGETDIR = ../../Build/VS2022/Release/Binaries/ThirdParty
TARGET = $(TARGETDIR)/MSDFATLASGEN.lib
OBJDIR = ../../Build/VS2022/Release/Objs/ThirdParty/MSDFATLASGEN
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64 -O2
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -O2 -std=c++17
LIBS += ../../Build/VS2022/Release/Binaries/ThirdParty/MSDFGEN.lib
LDDEPS += ../../Build/VS2022/Release/Binaries/ThirdParty/MSDFGEN.lib
ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -m64 -s

else ifeq ($(config),dist)
TARGETDIR = ../../Build/VS2022/Dist/Binaries/ThirdParty
TARGET = $(TARGETDIR)/MSDFATLASGEN.lib
OBJDIR = ../../Build/VS2022/Dist/Objs/ThirdParty/MSDFATLASGEN
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -std=c++17
LIBS += ../../Build/VS2022/Dist/Binaries/ThirdParty/MSDFGEN.lib
LDDEPS += ../../Build/VS2022/Dist/Binaries/ThirdParty/MSDFGEN.lib
ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -m64 -s

endif

# Per File Configurations
# #############################################


# File sets
# #############################################

GENERATED :=
OBJECTS :=

GENERATED += $(OBJDIR)/Charset.o
GENERATED += $(OBJDIR)/FontGeometry.o
GENERATED += $(OBJDIR)/GlyphGeometry.o
GENERATED += $(OBJDIR)/RectanglePacker.o
GENERATED += $(OBJDIR)/TightAtlasPacker.o
GENERATED += $(OBJDIR)/Workload.o
GENERATED += $(OBJDIR)/bitmap-blit.o
GENERATED += $(OBJDIR)/charset-parser.o
GENERATED += $(OBJDIR)/csv-export.o
GENERATED += $(OBJDIR)/glyph-generators.o
GENERATED += $(OBJDIR)/image-encode.o
GENERATED += $(OBJDIR)/json-export.o
GENERATED += $(OBJDIR)/main.o
GENERATED += $(OBJDIR)/shadron-preview-generator.o
GENERATED += $(OBJDIR)/size-selectors.o
GENERATED += $(OBJDIR)/utf8.o
OBJECTS += $(OBJDIR)/Charset.o
OBJECTS += $(OBJDIR)/FontGeometry.o
OBJECTS += $(OBJDIR)/GlyphGeometry.o
OBJECTS += $(OBJDIR)/RectanglePacker.o
OBJECTS += $(OBJDIR)/TightAtlasPacker.o
OBJECTS += $(OBJDIR)/Workload.o
OBJECTS += $(OBJDIR)/bitmap-blit.o
OBJECTS += $(OBJDIR)/charset-parser.o
OBJECTS += $(OBJDIR)/csv-export.o
OBJECTS += $(OBJDIR)/glyph-generators.o
OBJECTS += $(OBJDIR)/image-encode.o
OBJECTS += $(OBJDIR)/json-export.o
OBJECTS += $(OBJDIR)/main.o
OBJECTS += $(OBJDIR)/shadron-preview-generator.o
OBJECTS += $(OBJDIR)/size-selectors.o
OBJECTS += $(OBJDIR)/utf8.o

# Rules
# #############################################

all: $(TARGET)
	@:

$(TARGET): $(GENERATED) $(OBJECTS) $(LDDEPS) | $(TARGETDIR)
	$(PRELINKCMDS)
	@echo Linking MSDFATLASGEN
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
	@echo Cleaning MSDFATLASGEN
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

$(OBJDIR)/Charset.o: ../MSDFATLASGEN/msdf-atlas-gen/Charset.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/FontGeometry.o: ../MSDFATLASGEN/msdf-atlas-gen/FontGeometry.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/GlyphGeometry.o: ../MSDFATLASGEN/msdf-atlas-gen/GlyphGeometry.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/RectanglePacker.o: ../MSDFATLASGEN/msdf-atlas-gen/RectanglePacker.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TightAtlasPacker.o: ../MSDFATLASGEN/msdf-atlas-gen/TightAtlasPacker.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/Workload.o: ../MSDFATLASGEN/msdf-atlas-gen/Workload.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/bitmap-blit.o: ../MSDFATLASGEN/msdf-atlas-gen/bitmap-blit.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/charset-parser.o: ../MSDFATLASGEN/msdf-atlas-gen/charset-parser.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/csv-export.o: ../MSDFATLASGEN/msdf-atlas-gen/csv-export.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/glyph-generators.o: ../MSDFATLASGEN/msdf-atlas-gen/glyph-generators.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/image-encode.o: ../MSDFATLASGEN/msdf-atlas-gen/image-encode.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/json-export.o: ../MSDFATLASGEN/msdf-atlas-gen/json-export.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/main.o: ../MSDFATLASGEN/msdf-atlas-gen/main.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/shadron-preview-generator.o: ../MSDFATLASGEN/msdf-atlas-gen/shadron-preview-generator.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/size-selectors.o: ../MSDFATLASGEN/msdf-atlas-gen/size-selectors.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/utf8.o: ../MSDFATLASGEN/msdf-atlas-gen/utf8.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"

-include $(OBJECTS:%.o=%.d)
ifneq (,$(PCH))
  -include $(PCH_PLACEHOLDER).d
endif