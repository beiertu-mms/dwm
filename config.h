/* See LICENSE file for copyright and license details. */
#define FONT "JetBrainsMono Nerd Font"

/* appearance */
static const unsigned int borderpx = 1;        /* border pixel of windows */
static const unsigned int snap     = 32;       /* snap pixel */
static const int showbar           = 1;        /* 0 means no bar */
static const int topbar            = 1;        /* 0 means bottom bar */
static const char *fonts[]         = { FONT":size=9:style=Regular" };
static const char dmenufont[]      = FONT":size=9:style=Regular";
static const char norm_fg[]        = "#bbbbbb"; // "#88C0D0";
static const char norm_bg[]        = "#222222"; // "#2E3440";
static const char norm_border[]    = "#444444"; // "#4C566A";
static const char sel_fg[]         = "#eeeeee"; // "#EBCB8B";
static const char sel_bg[]         = "#005577"; // "#4C566A";
static const char sel_border[]     = "#005577"; // "#8FBCBB";
static const char *colors[][3]     = {
	/*               fg         bg          border   */
	[SchemeNorm] = { norm_fg,	norm_bg,	norm_border },
	[SchemeSel]  = { sel_fg,	sel_bg,		sel_border  },
};

/* tagging */
static const char *tags[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class            instance    title       tags mask     isfloating   monitor ignoretransient */
	{ "vivaldi-stable", NULL,       NULL,       1 << 1,       0,           -1,      0 },
	{ "jetbrains-idea", NULL,       NULL,       1 << 2,       0,           -1,      1 },
	{ "St",             NULL,       NULL,       1 << 0,       0,           -1,      0 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]      = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", norm_bg, "-nf", norm_fg, "-sb", sel_bg, "-sf", sel_fg, NULL };
static const char *rofiruncmd[]    = { "rofi", "-show", "run", NULL };
static const char *rofiwindowcmd[] = { "rofi", "-show", "window", NULL };
static const char *termcmd[]       = { "st", NULL };
static const char *ideacmd[]       = { "idea", NULL };
static const char *webcmd[]        = { "vivaldi-stable", NULL };
static const char *volumeupcmd[]   = { "volume", "up", NULL };
static const char *volumedowncmd[] = { "volume", "down", NULL };
static const char *micupcmd[]      = { "mic", "up", NULL };
static const char *micdowncmd[]    = { "mic", "down", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = rofiruncmd } },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          {.v = rofiwindowcmd } },
	{ MODKEY|ShiftMask,             XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_i,      spawn,          {.v = ideacmd } },
	{ MODKEY,                       XK_w,      spawn,          {.v = webcmd } },
	{ MODKEY,                       XK_Up,     spawn,          {.v = volumeupcmd } },
	{ MODKEY,                       XK_Down,   spawn,          {.v = volumedowncmd } },
	{ MODKEY,                       XK_Left,   spawn,          {.v = micdowncmd } },
	{ MODKEY,                       XK_Right,  spawn,          {.v = micupcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_period, focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_comma,  focusstack,     {.i = -1 } },
	{ MODKEY|ControlMask,           XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ControlMask,           XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_k,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_j,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_equal,  view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_equal,  tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_l,      focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_h,      focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_l,      tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,      tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_asterisk,               0)
	TAGKEYS(                        XK_parenleft,              1)
	TAGKEYS(                        XK_parenright,             2)
	TAGKEYS(                        XK_braceright,             3)
	TAGKEYS(                        XK_plus,                   4)
	TAGKEYS(                        XK_braceleft,              5)
	TAGKEYS(                        XK_bracketright,           6)
	TAGKEYS(                        XK_bracketleft,            7)
	TAGKEYS(                        XK_exclam,                 8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};

