#include <QWidget>
#import <Cocoa/Cocoa.h>

extern "C" void setupTitleBar(WId winId)
{
    // TODO: see https://www.youtube.com/watch?v=qfyxXxeC73Y @ 12:10 for example
    //       of how to make a full content view that is moveable

    if (winId == 0) return;

    NSView* view = (NSView*)winId;
    NSWindow* window = [view window];
    window.titlebarAppearsTransparent = YES;

    NSWindowStyleMask windowMask =
            NSWindowStyleMaskFullSizeContentView
                | NSWindowStyleMaskBorderless
                | NSWindowStyleMaskTitled
                | NSWindowStyleMaskClosable
                | NSWindowStyleMaskMiniaturizable
                | NSWindowStyleMaskResizable;

    [window setStyleMask: windowMask];
}
