// Copyright (c) 2011 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#ifndef CEF_TESTS_CEFCLIENT_CEFCLIENT_H_
#define CEF_TESTS_CEFCLIENT_CEFCLIENT_H_
#pragma once

#include <string>
#include <jni.h>
#include "include/cef_base.h"
#include "cefclient/client_app.h"
#include "cefclient/client_handler.h"

class CefApp;
class CefBrowser;
class CefCommandLine;

CefRefPtr<ClientHandler> InitBrowser(CefWindowHandle, CefString);
CefRefPtr<ClientHandler> NewBrowser(CefWindowHandle, CefString);
void CloseBrowser(jlong);
void ShutdownBrowser(jlong);
void CleanCookies();
void setUrl(jlong, CefString);
void resized(jlong, CefWindowHandle);
void back(jlong);
void forward(jlong);
void reload(jlong);

// Returns the main browser window instance.
CefRefPtr<CefBrowser> AppGetBrowser();

// Returns the main application window handle.
CefWindowHandle AppGetMainHwnd();

// Returns the application working directory.
std::string AppGetWorkingDirectory();

// Initialize the application command line.
void AppInitCommandLine(int argc, const char* const* argv);

// Returns the application command line object.
CefRefPtr<CefCommandLine> AppGetCommandLine();

// Returns the application settings based on command line arguments.
void AppGetSettings(CefSettings& settings);

// Returns true if off-screen rendering is enabled via the command line
// argument.
bool AppIsOffScreenRenderingEnabled();

// Implementations for various tests.
void RunGetSourceTest(CefRefPtr<CefBrowser> browser);
void RunGetTextTest(CefRefPtr<CefBrowser> browser);
void RunRequestTest(CefRefPtr<CefBrowser> browser);
void RunPopupTest(CefRefPtr<CefBrowser> browser);
void RunPluginInfoTest(CefRefPtr<CefBrowser> browser);
void RunLocalStorageTest(CefRefPtr<CefBrowser> browser);
void RunAccelerated2DCanvasTest(CefRefPtr<CefBrowser> browser);
void RunAcceleratedLayersTest(CefRefPtr<CefBrowser> browser);
void RunWebGLTest(CefRefPtr<CefBrowser> browser);
void RunHTML5VideoTest(CefRefPtr<CefBrowser> browser);
void RunXMLHTTPRequestTest(CefRefPtr<CefBrowser> browser);
void RunDragDropTest(CefRefPtr<CefBrowser> browser);
void RunGeolocationTest(CefRefPtr<CefBrowser> browser);
void RunTransparencyTest(CefRefPtr<CefBrowser> browser);

#if defined(OS_WIN)
void RunTransparentPopupTest(CefRefPtr<CefBrowser> browser);
#endif

#endif  // CEF_TESTS_CEFCLIENT_CEFCLIENT_H_
