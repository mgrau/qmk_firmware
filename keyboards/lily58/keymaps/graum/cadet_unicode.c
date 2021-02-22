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
    IBNG,
    F_1,
    F_2,
    F_3,
    F_4,
    F_5,
    F_6,
    F_7,
    F_8,
    F_9,
    F_0,
    F_11,
    F_12,
    F_q,
    F_w,
    F_e,
    F_r,
    F_t,
    F_y,
    F_u,
    F_i,
    F_o,
    F_p,
    F_Q,
    F_W,
    F_E,
    F_R,
    F_T,
    F_Y,
    F_U,
    F_I,
    F_O,
    F_P,
    F_a,
    F_s,
    F_d,
    F_f,
    F_g,
    F_h,
    F_j,
    F_k,
    F_l,
    F_A,
    F_S,
    F_D,
    F_F,
    F_G,
    F_H,
    F_J,
    F_K,
    F_L,
    F_z,
    F_x,
    F_c,
    F_v,
    F_b,
    F_n,
    F_m,
    F_Z,
    F_X,
    F_C,
    F_V,
    F_B,
    F_N,
    F_M,
    F_ll,
    F_gg,
    Fint,
    HBAR,
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
    [F_1]   = 0x2020,   // †
    [F_2]   = 0x2021,   // ‡
    [F_3]   = 0x2207,   // ∇
    [F_4]   = 0x00a2,   // ¢
    [F_5]   = 0x25cb,   // ○
    [F_6]   = 0x25af,   // ▯
    [F_7]   = 0x00f7,   // ÷
    [F_8]   = 0x00d7,   // ×
    [F_9]   = 0x00b6,   // ¶
    [F_0]   = 0x25ef,   // ◯
    [F_11]  = 0x2014,   // —
    [F_12]  = 0x2248,   // ≈

    [F_q]   = 0x03b8,   // θ
    [F_w]   = 0x03c9,   // ω
    [F_e]   = 0x03b5,   // ε
    [F_r]   = 0x03c1,   // ρ
    [F_t]   = 0x03c4,   // τ
    [F_y]   = 0x03c8,   // ψ
    [F_u]   = 0x03c5,   // υ
    [F_i]   = 0x03b9,   // ι
    [F_o]   = 0x03bf,   // ο
    [F_p]   = 0x03c0,   // π
    [F_Q]   = 0x0398,   // Θ
    [F_W]   = 0x03a9,   // Ω
    [F_E]   = 0x0395,   // Ε
    [F_R]   = 0x03a1,   // Ρ
    [F_T]   = 0x03a4,   // Τ
    [F_Y]   = 0x03a8,   // Ψ
    [F_U]   = 0x03a5,   // Υ
    [F_I]   = 0x0399,   // ι
    [F_O]   = 0x039f,   // Ο
    [F_P]   = 0x03a0,   // Π

    [F_a]   = 0x03B1,   // α
    [F_s]   = 0x03C3,   // σ
    [F_d]   = 0x03B4,   // δ
    [F_f]   = 0x03C6,   // φ
    [F_g]   = 0x03B3,   // γ
    [F_h]   = 0x03B7,   // η
    [F_j]   = 0x03DB,   // ϛ
    [F_k]   = 0x03BA,   // κ
    [F_l]   = 0x03BB,   // λ
    [F_A]   = 0x0391,   // Α
    [F_S]   = 0x03A3,   // Σ
    [F_D]   = 0x0394,   // Δ
    [F_F]   = 0x03A6,   // Φ
    [F_G]   = 0x0393,   // Γ
    [F_H]   = 0x0397,   // Η
    [F_J]   = 0x03DA,   // Ϛ
    [F_K]   = 0x039A,   // Κ
    [F_L]   = 0x039B,   // Λ

    [F_z]   = 0x03B6,   // ζ
    [F_x]   = 0x03BE,   // ξ
    [F_c]   = 0x03C7,   // χ
    [F_v]   = 0x03E9,   // ϩ
    [F_b]   = 0x03B2,   // β
    [F_n]   = 0x03BD,   // ν
    [F_m]   = 0x03BC,   // μ
    [F_Z]   = 0x0396,   // Ζ
    [F_X]   = 0x039E,   // Ξ
    [F_C]   = 0x03A7,   // Χ
    [F_V]   = 0x03E8,   // Ϩ
    [F_B]   = 0x0392,   // Β
    [F_N]   = 0x039D,   // Ν
    [F_M]   = 0x039C,   // Μ
    [F_ll]  = 0x226A,   // ≪
    [F_gg]  = 0x226B,   // ≫
    [Fint]  = 0x222B,   // ∫
    [HBAR]  = 0x210F,   // ℏ

};

#define GK_A XP(F_a, F_A)
#define GK_B XP(F_b, F_B)
#define GK_C XP(F_c, F_C)
#define GK_D XP(F_d, F_D)
#define GK_E XP(F_e, F_E)
#define GK_F XP(F_f, F_F)
#define GK_G XP(F_g, F_G)
#define GK_H XP(F_h, HBAR)
#define GK_I XP(F_i, F_I)
#define GK_J XP(F_j, F_J)
#define GK_K XP(F_k, F_K)
#define GK_L XP(F_l, F_L)
#define GK_M XP(F_m, F_M)
#define GK_N XP(F_n, F_N)
#define GK_O XP(F_o, F_O)
#define GK_P XP(F_p, F_P)
#define GK_Q XP(F_q, F_Q)
#define GK_R XP(F_r, F_R)
#define GK_S XP(F_s, F_S)
#define GK_T XP(F_t, F_T)
#define GK_U XP(F_u, F_U)
#define GK_V XP(F_v, F_V)
#define GK_W XP(F_w, F_W)
#define GK_X XP(F_x, F_X)
#define GK_Y XP(F_y, F_Y)
#define GK_Z XP(F_z, F_Z)
