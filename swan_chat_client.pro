QT += quick qml
#QT += core5compat

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ModelFactory.cpp \
        UiBackend.cpp \
        main.cpp \
        models/RoomModel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ModelFactory.h \
    UiBackend.h \
    models/RoomModel.h


UI_DIR = uics
MOC_DIR = mocs
OBJECTS_DIR = objs

#defineTest(extractFileOut) {
#    fileIn = $$1
#    fileOut = $$2

#    win32-g++{
#        EXTRA_BINFILES_FOLDER += \
#            $$_PRO_FILE_PWD_/$$fileIn
#        EXTRA_BINFILES_FOLDER ~= s,/,\\,g

#        message($$EXTRA_BINFILES_FOLDER)

#        ADD_CHANGE_PATH = $$OUT_PWD$$/$$fileOut
#        ADD_CHANGE_PATH ~= s,/,\\,g

#        for (FILE, EXTRA_BINFILES_FOLDER) {
##            QMAKE_POST_LINK += $$quote(copy /Y $$shell_quote($$FILE) $$shell_quote($$ADD_CHANGE_PATH) $$escape_expand(\n\t))
#            QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$fileIn) $$quote($$DDIR) $$escape_expand(\\n\\t)
#        }
#        export(QMAKE_POST_LINK)
#        return(true)
#    }
#}

defineTest(extractFileOut) {
    FILE = $$1
    DDIR = $$2

    win32-g++{
        FULL_FILE_NAME += \
            $$_PRO_FILE_PWD_/$$FILE
        FULL_FILE_NAME ~= s,/,\\,g

        message($$FULL_FILE_NAME)

        ADD_CHANGE_PATH = $$OUT_PWD$$/$$DDIR
        ADD_CHANGE_PATH ~= s,/,\\,g

        QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$FULL_FILE_NAME) $$quote($$ADD_CHANGE_PATH) $$escape_expand(\\n\\t)

        export(QMAKE_POST_LINK)
        return(true)
    }
}

shared {
    CONFIG(debug, debug|release) {
        !extractFileOut(icons/test_room_imag_1.png, debug/test_room_imag_1.png) {
            error("Not required files for test SectionId.xml!")
        }
    }
}


