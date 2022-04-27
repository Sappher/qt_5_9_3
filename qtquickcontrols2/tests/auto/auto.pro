TEMPLATE = subdirs
SUBDIRS += \
    accessibility \
    calendar \
    controls \
    cursor \
    focus \
    font \
    platform \
    pressandhold \
    qquickapplicationwindow \
    qquickdrawer \
    qquickmaterialstyle \
    qquickmaterialstyleconf \
    qquickmenu \
    qquickpopup \
    qquickstyle \
    qquickstyleselector \
    qquickuniversalstyle \
    qquickuniversalstyleconf \
    revisions \
    sanity \
    snippets

# QTBUG-60268
boot2qt: SUBDIRS -= qquickapplicationwindow calendar controls cursor \
                    qquickdrawer focus font qquickmenu platform qquickpopup qquickmaterialstyle \
                    qquickmaterialstyleconf qquickuniversalstyle \
                    qquickuniversalstyleconf snippets
