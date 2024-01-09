// Copyright (C) 2024 owoDra

#pragma once

#include "Logging/LogMacros.h"

GCVINTG_API DECLARE_LOG_CATEGORY_EXTERN(LogGCVI, Log, All);

#if !UE_BUILD_SHIPPING

#define GCVILOG(FormattedText, ...) UE_LOG(LogGCVI, Log, FormattedText, __VA_ARGS__)

#define GCVIENSURE(InExpression) ensure(InExpression)
#define GCVIENSURE_MSG(InExpression, InFormat, ...) ensureMsgf(InExpression, InFormat, __VA_ARGS__)
#define GCVIENSURE_ALWAYS_MSG(InExpression, InFormat, ...) ensureAlwaysMsgf(InExpression, InFormat, __VA_ARGS__)

#define GCVICHECK(InExpression) check(InExpression)
#define GCVICHECK_MSG(InExpression, InFormat, ...) checkf(InExpression, InFormat, __VA_ARGS__)

#else

#define GCVILOG(FormattedText, ...)

#define GCVIENSURE(InExpression) InExpression
#define GCVIENSURE_MSG(InExpression, InFormat, ...) InExpression
#define GCVIENSURE_ALWAYS_MSG(InExpression, InFormat, ...) InExpression

#define GCVICHECK(InExpression) InExpression
#define GCVICHECK_MSG(InExpression, InFormat, ...) InExpression

#endif