#pragma once

#ifdef _WINDOWS
#pragma warning(disable:4530)
#pragma warning(disable:4068)
#endif

#define __STRINGIFY__(x)            #x
#define __EXPAND__(x)               __STRINGIFY__(x)

#define APP_NAME                    "CuteOwl"
#define APP_TITLE					APP_NAME " " OWL_VERSION

#define ORGANZATION_DOMAIN          "owlclient.com"

#ifdef Q_OS_MACOS
#define ORGANIZATION_NAME			"Adalid Claure"
#else
#define ORGANIZATION_NAME			"lulzApps"
#endif

#define OWL_VERSION_MAJOR			0
#define	OWL_VERSION_MINOR			1
#define OWL_VERSION_PATCH			0
#define OWL_VERSION					__EXPAND__(OWL_VERSION_MAJOR) "." __EXPAND__(OWL_VERSION_MINOR) "." __EXPAND__(OWL_VERSION_PATCH)
#define OWL_VERSION_DATE_TIME		__DATE__ " " __TIME__

#define COPYRIGHT                   "Copyright (c) 2022 " ORGANIZATION_NAME ". All Rights Reserved."
