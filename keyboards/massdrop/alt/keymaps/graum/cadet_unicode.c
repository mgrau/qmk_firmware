enum unicode_names {
    AND,
    OR,
    INSC,
    UNI,
    SUB,
    SUP,
    FALL,
    INF,
    EXIS,
    PART,
    UPTK,
    DNTK,
    RTTK,
    LTTK,
    LRAR,
    LARR,
    DARR,
    UARR,
    RARR,
    LDO,
    LUP,
    NOTE,
    ASYM,
    EQIV,
    LEQ,
    GEQ,
    IBNG
};

const uint32_t PROGMEM unicode_map[] = {
    [AND]   = 0x2227,   // ∧
    [OR]    = 0x2228,   // ∨
    [INSC]  = 0x2229,   // ∩
    [UNI]   = 0x222a,   // ∪
    [SUB]   = 0x2282,   // ⊂
    [SUP]   = 0x2283,   // ⊃
    [FALL]  = 0x2200,   // ∀
    [INF]   = 0x221e,   // ∞
    [EXIS]  = 0x2203,   // ∃
    [PART]  = 0x2202,   // ∂

    [UPTK]  = 0x22a5,   // ⊥
    [DNTK]  = 0x22a4,   // ⊤
    [RTTK]  = 0x22a2,   // ⊢
    [LTTK]  = 0x22a3,   // ⊣
    [LRAR]  = 0x2194,   // ↔
    [LARR]  = 0x2190,   // ←
    [DARR]  = 0x2193,   // ↓
    [UARR]  = 0x2191,   // ↑
    [RARR]  = 0x2192,   // →

    [LDO]   = 0x23a3,   // ⎣
    [LUP]   = 0x23a1,   // ⎡
    [NOTE]  = 0x2260,   // ≠
    [ASYM]  = 0x2243,   // ≃
    [EQIV]  = 0x2263,   // ≣
    [LEQ]   = 0x2264,   // ≤
    [GEQ]   = 0x2265,   // ≥

    [IBNG]  = 0x203d,   // ‽
};

