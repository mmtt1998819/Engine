#pragma once

#include "Foundation/Profile.h"

#define HELIUM_EDITOR_PROFILE 0

#if HELIUM_PROFILE_INSTRUMENT_ALL || HELIUM_EDITOR_PROFILE
# define HELIUM_EDITOR_SCOPE_TIMER( ... ) HELIUM_PROFILE_SCOPE_TIMER( __VA_ARGS__ )
#else
# define HELIUM_EDITOR_SCOPE_TIMER( ... )
#endif

#define HELIUM_EDITOR_PROFILE_RENDER 0

#if HELIUM_PROFILE_INSTRUMENT_ALL || HELIUM_EDITOR_PROFILE_RENDER
# define HELIUM_EDITOR_RENDER_SCOPE_TIMER( ... ) HELIUM_PROFILE_SCOPE_TIMER( __VA_ARGS__ )
#else
# define HELIUM_EDITOR_RENDER_SCOPE_TIMER( ... )
#endif