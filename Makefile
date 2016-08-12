#############################################################################
# Makefile for building: libConnectFour
# Generated by qmake (3.0) (Qt 5.5.1)
# Project:  ConnectFour.pro
# Template: vcapp
# Command: D:\Programs\Qt\5.5\mingw492_32\bin\qmake.exe -t vcapp -o Makefile ConnectFour.pro
#############################################################################

MAKEFILE      = Makefile

first: release
install: release-install
uninstall: release-uninstall
QMAKE         = D:\Programs\Qt\5.5\mingw492_32\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		release \
		debug


release: FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall
debug: FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall

Makefile: ConnectFour.pro D:/Programs/Qt/5.5/mingw492_32/mkspecs/win32-g++/qmake.conf D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/spec_pre.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/qdevice.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/device_config.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/qconfig.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dcollision.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dcollision_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dcore.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dcore_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dinput.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dinput_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dlogic.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dlogic_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dquick.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dquick_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dquickrenderer.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dquickrenderer_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3drenderer.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3drenderer_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_axbase.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_axbase_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_axcontainer.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_axcontainer_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_axserver.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_axserver_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_bluetooth.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_bluetooth_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_bootstrap_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_clucene_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_concurrent.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_concurrent_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_core.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_core_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_dbus.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_dbus_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_declarative.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_declarative_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_designer.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_designer_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_designercomponents_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_enginio.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_enginio_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_gui.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_gui_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_help.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_help_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_location.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_location_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_multimedia.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_multimedia_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_multimediawidgets.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_network.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_network_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_nfc.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_nfc_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_opengl.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_opengl_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_openglextensions.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_openglextensions_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_platformsupport_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_positioning.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_positioning_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_printsupport.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_printsupport_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_qml.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_qml_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_qmltest.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_qmltest_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_quick.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_quick_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_quickparticles_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_quickwidgets.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_script.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_script_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_scripttools.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_scripttools_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_sensors.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_sensors_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_serialport.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_serialport_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_sql.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_sql_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_svg.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_svg_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_testlib.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_testlib_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_uiplugin.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_uitools.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_uitools_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_webchannel.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_webchannel_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_webkit.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_webkit_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_webkitwidgets.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_websockets.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_websockets_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_widgets.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_widgets_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_winextras.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_winextras_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_xml.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_xml_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_xmlpatterns.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/qt_functions.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/qt_config.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/win32/qt_config.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/win32-g++/qmake.conf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/spec_post.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/exclusive_builds.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/default_pre.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/win32/default_pre.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/resolve_config.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/exclusive_builds_post.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/default_post.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/win32/rtti.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/precompile_header.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/warn_on.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/qt.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/resources.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/moc.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/win32/opengl.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/uic.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/win32/windows.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/testcase_targets.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/exceptions.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/yacc.prf \
		D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/lex.prf \
		ConnectFour.pro \
		D:/Programs/Qt/5.5/mingw492_32/lib/qtmain.prl \
		D:/Programs/Qt/5.5/mingw492_32/lib/Qt5Widgets.prl \
		D:/Programs/Qt/5.5/mingw492_32/lib/Qt5Gui.prl \
		D:/Programs/Qt/5.5/mingw492_32/lib/Qt5Core.prl
	$(QMAKE) -t vcapp -o Makefile ConnectFour.pro
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/spec_pre.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/qdevice.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/device_config.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/qconfig.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dcollision.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dcollision_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dcore.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dcore_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dinput.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dinput_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dlogic.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dlogic_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dquick.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dquick_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dquickrenderer.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3dquickrenderer_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3drenderer.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_3drenderer_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_axbase.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_axbase_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_axcontainer.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_axcontainer_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_axserver.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_axserver_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_bluetooth.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_bluetooth_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_bootstrap_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_clucene_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_concurrent.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_concurrent_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_core.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_core_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_dbus.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_dbus_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_declarative.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_declarative_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_designer.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_designer_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_designercomponents_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_enginio.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_enginio_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_gui.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_gui_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_help.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_help_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_location.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_location_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_multimedia.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_multimedia_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_multimediawidgets.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_network.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_network_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_nfc.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_nfc_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_opengl.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_opengl_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_openglextensions.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_openglextensions_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_platformsupport_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_positioning.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_positioning_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_printsupport.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_printsupport_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_qml.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_qml_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_qmldevtools_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_qmltest.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_qmltest_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_quick.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_quick_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_quickparticles_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_quickwidgets.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_quickwidgets_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_script.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_script_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_scripttools.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_scripttools_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_sensors.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_sensors_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_serialport.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_serialport_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_sql.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_sql_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_svg.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_svg_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_testlib.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_testlib_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_uiplugin.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_uitools.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_uitools_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_webchannel.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_webchannel_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_webkit.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_webkit_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_webkitwidgets.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_webkitwidgets_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_websockets.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_websockets_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_widgets.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_widgets_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_winextras.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_winextras_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_xml.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_xml_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_xmlpatterns.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/qt_functions.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/qt_config.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/win32/qt_config.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/win32-g++/qmake.conf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/spec_post.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/exclusive_builds.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/default_pre.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/win32/default_pre.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/resolve_config.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/exclusive_builds_post.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/default_post.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/win32/rtti.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/precompile_header.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/warn_on.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/qt.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/resources.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/moc.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/win32/opengl.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/uic.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/win32/windows.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/testcase_targets.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/exceptions.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/yacc.prf:
D:/Programs/Qt/5.5/mingw492_32/mkspecs/features/lex.prf:
ConnectFour.pro:
D:/Programs/Qt/5.5/mingw492_32/lib/qtmain.prl:
D:/Programs/Qt/5.5/mingw492_32/lib/Qt5Widgets.prl:
D:/Programs/Qt/5.5/mingw492_32/lib/Qt5Gui.prl:
D:/Programs/Qt/5.5/mingw492_32/lib/Qt5Core.prl:
qmake: FORCE
	@$(QMAKE) -t vcapp -o Makefile ConnectFour.pro

qmake_all: FORCE

make_first: release-make_first debug-make_first  FORCE
all: release-all debug-all  FORCE
clean: release-clean debug-clean  FORCE
distclean: release-distclean debug-distclean  FORCE
	-$(DEL_FILE) Makefile

release-mocclean:
	$(MAKE) -f $(MAKEFILE).Release mocclean
debug-mocclean:
	$(MAKE) -f $(MAKEFILE).Debug mocclean
mocclean: release-mocclean debug-mocclean

release-mocables:
	$(MAKE) -f $(MAKEFILE).Release mocables
debug-mocables:
	$(MAKE) -f $(MAKEFILE).Debug mocables
mocables: release-mocables debug-mocables

check: first
FORCE:

$(MAKEFILE).Release: Makefile
$(MAKEFILE).Debug: Makefile