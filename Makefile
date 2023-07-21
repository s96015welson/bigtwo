#############################################################################
# Makefile for building: bigtwo.exe
# Generated by qmake (3.1) (Qt 5.9.4)
# Project:  bigtwo.pro
# Template: app
# Command: /usr/bin/qmake-qt5 -o Makefile bigtwo.pro QT+=widgets 'QT+=core gui' 'QT+=widgets multimedia'
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_MULTIMEDIA_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB
CFLAGS        = -fno-keep-inline-dllexport -D_GNU_SOURCE -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -fno-keep-inline-dllexport -D_GNU_SOURCE -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I. -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtMultimedia -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtNetwork -isystem /usr/include/qt5/QtCore -I. -I/usr/lib/qt5/mkspecs/cygwin-g++
QMAKE         = /usr/bin/qmake-qt5
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /usr/bin/qmake-qt5 -install qinstall
QINSTALL_PROGRAM = /usr/bin/qmake-qt5 -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = bigtwo1.0.0
DISTDIR = /home/s9601/bigtwo/.tmp/bigtwo1.0.0
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS) -lQt5Widgets -lQt5Multimedia -lQt5Gui -lQt5Network -lQt5Core -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = 

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = Card.cpp \
		Combination.cpp \
		four_of_a_kind.cpp \
		Game.cpp \
		main.cpp \
		Player.cpp moc_Card.cpp \
		moc_Combination.cpp \
		moc_four_of_a_kind.cpp \
		moc_Game.cpp \
		moc_Player.cpp
OBJECTS       = Card.o \
		Combination.o \
		four_of_a_kind.o \
		Game.o \
		main.o \
		Player.o \
		moc_Card.o \
		moc_Combination.o \
		moc_four_of_a_kind.o \
		moc_Game.o \
		moc_Player.o
DIST          = /usr/lib/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/qt5/mkspecs/common/unix.conf \
		/usr/lib/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/qt5/mkspecs/qconfig.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_multimedia.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_multimedia_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qml_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qmldebug_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qmltest_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quick_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/qt5/mkspecs/cygwin-g++/qmake.conf \
		/usr/lib/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/qt5/mkspecs/features/default_post.prf \
		/usr/lib/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/qt5/mkspecs/features/qt.prf \
		/usr/lib/qt5/mkspecs/features/resources.prf \
		/usr/lib/qt5/mkspecs/features/moc.prf \
		/usr/lib/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/qt5/mkspecs/features/uic.prf \
		/usr/lib/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/qt5/mkspecs/features/yacc.prf \
		/usr/lib/qt5/mkspecs/features/lex.prf \
		bigtwo.pro Card.h \
		Combination.h \
		four_of_a_kind.h \
		Game.h \
		Parameter.h \
		Player.h Card.cpp \
		Combination.cpp \
		four_of_a_kind.cpp \
		Game.cpp \
		main.cpp \
		Player.cpp
QMAKE_TARGET  = bigtwo
DESTDIR       = 
TARGET        = bigtwo.exe


first: all
####### Build rules

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: bigtwo.pro /usr/lib/qt5/mkspecs/cygwin-g++/qmake.conf /usr/lib/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/qt5/mkspecs/common/unix.conf \
		/usr/lib/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/qt5/mkspecs/qconfig.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_multimedia.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_multimedia_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qml_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qmldebug_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qmltest_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quick_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/qt5/mkspecs/cygwin-g++/qmake.conf \
		/usr/lib/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/qt5/mkspecs/features/default_post.prf \
		/usr/lib/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/qt5/mkspecs/features/qt.prf \
		/usr/lib/qt5/mkspecs/features/resources.prf \
		/usr/lib/qt5/mkspecs/features/moc.prf \
		/usr/lib/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/qt5/mkspecs/features/uic.prf \
		/usr/lib/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/qt5/mkspecs/features/yacc.prf \
		/usr/lib/qt5/mkspecs/features/lex.prf \
		bigtwo.pro
	$(QMAKE) -o Makefile bigtwo.pro QT+=widgets 'QT+=core gui' 'QT+=widgets multimedia'
/usr/lib/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/qt5/mkspecs/common/unix.conf:
/usr/lib/qt5/mkspecs/common/sanitize.conf:
/usr/lib/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/qt5/mkspecs/common/g++-base.conf:
/usr/lib/qt5/mkspecs/qconfig.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_fb_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_glx_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_multimedia.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_multimedia_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_multimediawidgets.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_packetprotocol_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_qml.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_qml_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_qmldebug_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_qmltest.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_qmltest_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_quick.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_quick_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_quickparticles_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_quickwidgets.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_quickwidgets_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_service_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_theme_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/qt5/mkspecs/features/qt_config.prf:
/usr/lib/qt5/mkspecs/cygwin-g++/qmake.conf:
/usr/lib/qt5/mkspecs/features/spec_post.prf:
.qmake.stash:
/usr/lib/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/qt5/mkspecs/features/toolchain.prf:
/usr/lib/qt5/mkspecs/features/default_pre.prf:
/usr/lib/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/qt5/mkspecs/features/default_post.prf:
/usr/lib/qt5/mkspecs/features/warn_on.prf:
/usr/lib/qt5/mkspecs/features/qt.prf:
/usr/lib/qt5/mkspecs/features/resources.prf:
/usr/lib/qt5/mkspecs/features/moc.prf:
/usr/lib/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib/qt5/mkspecs/features/uic.prf:
/usr/lib/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/qt5/mkspecs/features/qmake_use.prf:
/usr/lib/qt5/mkspecs/features/file_copies.prf:
/usr/lib/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/qt5/mkspecs/features/exceptions.prf:
/usr/lib/qt5/mkspecs/features/yacc.prf:
/usr/lib/qt5/mkspecs/features/lex.prf:
bigtwo.pro:
qmake: FORCE
	@$(QMAKE) -o Makefile bigtwo.pro QT+=widgets 'QT+=core gui' 'QT+=widgets multimedia'

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents /usr/lib/qt5/mkspecs/features/data/dummy.cpp $(DISTDIR)/
	$(COPY_FILE) --parents Card.h Combination.h four_of_a_kind.h Game.h Parameter.h Player.h $(DISTDIR)/
	$(COPY_FILE) --parents Card.cpp Combination.cpp four_of_a_kind.cpp Game.cpp main.cpp Player.cpp $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_predefs_make_all: moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) moc_predefs.h
moc_predefs.h: /usr/lib/qt5/mkspecs/features/data/dummy.cpp
	g++ -fno-keep-inline-dllexport -D_GNU_SOURCE -pipe -O2 -Wall -W -dM -E -o moc_predefs.h /usr/lib/qt5/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: moc_Card.cpp moc_Combination.cpp moc_four_of_a_kind.cpp moc_Game.cpp moc_Player.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_Card.cpp moc_Combination.cpp moc_four_of_a_kind.cpp moc_Game.cpp moc_Player.cpp
moc_Card.cpp: Parameter.h \
		Card.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/qt5/mkspecs/cygwin-g++ -I/home/s9601/bigtwo -I/home/s9601/bigtwo -I/usr/include/qt5 -I/usr/include/qt5/QtWidgets -I/usr/include/qt5/QtMultimedia -I/usr/include/qt5/QtGui -I/usr/include/qt5/QtNetwork -I/usr/include/qt5/QtCore -I/usr/lib/gcc/x86_64-pc-cygwin/11/include/c++ -I/usr/lib/gcc/x86_64-pc-cygwin/11/include/c++/x86_64-pc-cygwin -I/usr/lib/gcc/x86_64-pc-cygwin/11/include/c++/backward -I/usr/lib/gcc/x86_64-pc-cygwin/11/include -I/usr/include -I/usr/include/w32api Card.h -o moc_Card.cpp

moc_Combination.cpp: Parameter.h \
		Player.h \
		Combination.h \
		Card.h \
		Combination.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/qt5/mkspecs/cygwin-g++ -I/home/s9601/bigtwo -I/home/s9601/bigtwo -I/usr/include/qt5 -I/usr/include/qt5/QtWidgets -I/usr/include/qt5/QtMultimedia -I/usr/include/qt5/QtGui -I/usr/include/qt5/QtNetwork -I/usr/include/qt5/QtCore -I/usr/lib/gcc/x86_64-pc-cygwin/11/include/c++ -I/usr/lib/gcc/x86_64-pc-cygwin/11/include/c++/x86_64-pc-cygwin -I/usr/lib/gcc/x86_64-pc-cygwin/11/include/c++/backward -I/usr/lib/gcc/x86_64-pc-cygwin/11/include -I/usr/include -I/usr/include/w32api Combination.h -o moc_Combination.cpp

moc_four_of_a_kind.cpp: Parameter.h \
		Combination.h \
		Player.h \
		Card.h \
		four_of_a_kind.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/qt5/mkspecs/cygwin-g++ -I/home/s9601/bigtwo -I/home/s9601/bigtwo -I/usr/include/qt5 -I/usr/include/qt5/QtWidgets -I/usr/include/qt5/QtMultimedia -I/usr/include/qt5/QtGui -I/usr/include/qt5/QtNetwork -I/usr/include/qt5/QtCore -I/usr/lib/gcc/x86_64-pc-cygwin/11/include/c++ -I/usr/lib/gcc/x86_64-pc-cygwin/11/include/c++/x86_64-pc-cygwin -I/usr/lib/gcc/x86_64-pc-cygwin/11/include/c++/backward -I/usr/lib/gcc/x86_64-pc-cygwin/11/include -I/usr/include -I/usr/include/w32api four_of_a_kind.h -o moc_four_of_a_kind.cpp

moc_Game.cpp: Parameter.h \
		Card.h \
		Player.h \
		Combination.h \
		Game.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/qt5/mkspecs/cygwin-g++ -I/home/s9601/bigtwo -I/home/s9601/bigtwo -I/usr/include/qt5 -I/usr/include/qt5/QtWidgets -I/usr/include/qt5/QtMultimedia -I/usr/include/qt5/QtGui -I/usr/include/qt5/QtNetwork -I/usr/include/qt5/QtCore -I/usr/lib/gcc/x86_64-pc-cygwin/11/include/c++ -I/usr/lib/gcc/x86_64-pc-cygwin/11/include/c++/x86_64-pc-cygwin -I/usr/lib/gcc/x86_64-pc-cygwin/11/include/c++/backward -I/usr/lib/gcc/x86_64-pc-cygwin/11/include -I/usr/include -I/usr/include/w32api Game.h -o moc_Game.cpp

moc_Player.cpp: Parameter.h \
		Combination.h \
		Player.h \
		Card.h \
		Player.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/qt5/mkspecs/cygwin-g++ -I/home/s9601/bigtwo -I/home/s9601/bigtwo -I/usr/include/qt5 -I/usr/include/qt5/QtWidgets -I/usr/include/qt5/QtMultimedia -I/usr/include/qt5/QtGui -I/usr/include/qt5/QtNetwork -I/usr/include/qt5/QtCore -I/usr/lib/gcc/x86_64-pc-cygwin/11/include/c++ -I/usr/lib/gcc/x86_64-pc-cygwin/11/include/c++/x86_64-pc-cygwin -I/usr/lib/gcc/x86_64-pc-cygwin/11/include/c++/backward -I/usr/lib/gcc/x86_64-pc-cygwin/11/include -I/usr/include -I/usr/include/w32api Player.h -o moc_Player.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_predefs_clean compiler_moc_header_clean 

####### Compile

Card.o: Card.cpp Parameter.h \
		Card.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Card.o Card.cpp

Combination.o: Combination.cpp Parameter.h \
		Combination.h \
		Player.h \
		Card.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Combination.o Combination.cpp

four_of_a_kind.o: four_of_a_kind.cpp Parameter.h \
		Combination.h \
		Player.h \
		Card.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o four_of_a_kind.o four_of_a_kind.cpp

Game.o: Game.cpp Game.h \
		Parameter.h \
		Card.h \
		Player.h \
		Combination.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Game.o Game.cpp

main.o: main.cpp Game.h \
		Parameter.h \
		Card.h \
		Player.h \
		Combination.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

Player.o: Player.cpp Parameter.h \
		Player.h \
		Combination.h \
		Card.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Player.o Player.cpp

moc_Card.o: moc_Card.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Card.o moc_Card.cpp

moc_Combination.o: moc_Combination.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Combination.o moc_Combination.cpp

moc_four_of_a_kind.o: moc_four_of_a_kind.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_four_of_a_kind.o moc_four_of_a_kind.cpp

moc_Game.o: moc_Game.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Game.o moc_Game.cpp

moc_Player.o: moc_Player.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Player.o moc_Player.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:
