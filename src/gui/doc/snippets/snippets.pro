TEMPLATE = subdirs
SUBDIRS =

contains(QT_BUILD_PARTS, tests) {
    SUBDIRS += \
        brush \
        clipboard \
        code \
        draganddrop \
        droparea \
        dropevents \
        droprectangle \
        image \
        picture \
        plaintextlayout \
        qfontdatabase \
        textblock-formats \
        textblock-fragments \
        textdocument-blocks \
        textdocument-charformats \
        textdocument-css \
        textdocument-cursors \
        textdocument-end \
        textdocument-find \
        textdocument-frames \
        textdocument-imagedrop \
        textdocument-imageformat \
        textdocument-images \
        textdocument-listitems \
        textdocument-listitemstyles \
        textdocument-lists \
        textdocument-printing \
        textdocument-resources \
        textdocument-selections \
        textdocument-tables \
        textdocument-texttable
}
