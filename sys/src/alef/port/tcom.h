
/* Type combination tables */
char
moptype[Ntype][Ntype] =
{
/*              X   L  UL   I  UI   S  US   C   F   *  CH  []   A   U F() void ADT PLY*/
/* TXXX   */	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TLINT  */	0,  1,  2,  1,  2,  1,  2,  2,  8,  9,  0,  0,  0,  0,  0,  0,	0,  0,
/* TLUINT */	0,  2,  2,  2,  2,  2,  2,  2,  8,  9,  0,  0,  0,  0,  0,  0,	0,  0,
/* TINT   */	0,  1,  2,  3,  4,  3,  4,  4,  8,  9,  0,  0,  0,  0,  0,  0,	0,  0,
/* TUINT  */	0,  2,  2,  4,  4,  4,  4,  4,  8,  9,  0,  0,  0,  0,  0,  0,	0,  0,
/* TSINT  */	0,  1,  2,  3,  4,  3,  4,  4,  8,  9,  0,  0,  0,  0,  0,  0,	0,  0,
/* TSUINT */	0,  2,  2,  4,  4,  4,  4,  4,  8,  9,  0,  0,  0,  0,  0,  0,	0,  0,
/* TCHAR  */	0,  0,  0,  4,  4,  4,  4,  4,  8,  9,  0,  0,  0,  0,  0,  0,	0,  0,
/* TFLOAT */	0,  0,  0,  8,  8,  8,  8,  8,  8,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TIND   */	0,  9,  9,  9,  9,  9,  9,  9,  0,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TCHAN  */	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TARRAY */	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TAGGR  */	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TUNION */	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TFUNC  */	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TVOID  */	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TADT   */	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TPOLY  */	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,	0,  0,
};

char
logtype[Ntype][Ntype] =
{
/*              X   L  UL   I  UI   S  US   C   F   *  CH  []   A   U F() void ADT PLY*/
/* TXXX   */	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TLINT  */	0,  1,  2,  1,  2,  1,  2,  2,  8,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TLUINT */	0,  2,  2,  2,  2,  2,  2,  2,  8,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TINT   */	0,  1,  2,  3,  4,  3,  4,  4,  8,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TUINT  */	0,  2,  2,  4,  4,  4,  4,  4,  8,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TSINT  */	0,  1,  2,  3,  4,  3,  4,  4,  8,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TSUINT */	0,  2,  2,  4,  4,  4,  4,  4,  8,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TCHAR  */	0,  0,  0,  4,  4,  4,  4,  4,  8,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TFLOAT */	0,  0,  0,  8,  8,  8,  8,  8,  8,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TIND   */	0,  0,  0,  0,  0,  0,  0,  0,  0,  9,  0,  0,  0,  0,  0,  0,	0,  0,
/* TCHAN  */	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TARRAY */	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TAGGR  */	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TUNION */	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TFUNC  */	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TVOID  */	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TADT   */	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,	0,  0,
/* TPOLY  */	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,	0,  0,
};

ulong
typeasgn[Ntype] =
{
	0,			/* TXXX */
	MARITH,			/* TLINT */
	MARITH,			/* TLUINT */
	MARITH,			/* TINT */
	MARITH,			/* TUINT */
	MARITH,			/* TSINT */
	MARITH,			/* TSUINT */
	MARITH,			/* TCHAR */
	MARITH,			/* TFLOAT */
	0,			/* TIND */
	0,			/* TCHANNEL */
	0,			/* TARRAY */
	0,			/* TAGGREGATE */
	0,			/* TUNION */
	0,			/* TFUNC */
	0,			/* TVOID */
	0,			/* TADT */
	0,			/* TPOLY */
};

ulong
convtab[Ntype] =
{
	0,			/* TXXX */
	MARITH|MIND,		/* TLINT */
	MARITH|MIND,		/* TLUINT */
	MARITH|MIND,		/* TINT */
	MARITH|MIND,		/* TUINT */
	MARITH,			/* TSINT */
	MARITH,			/* TSUINT */
	MARITH,			/* TCHAR */
	MARITH,			/* TFLOAT */
	MCONVIND,		/* TIND */
	0,			/* TCHANNEL */
	0,			/* TARRAY */
	0,			/* TAGGREGATE */
	0,			/* TUNION */
	0,			/* TFUNC */
	0,			/* TVOID */
	0,			/* TADT */
	0,			/* TPOLY */
};

ulong
typeaddasgn[Ntype] =
{
	0,			/* TXXX */
	MARITH|MIND,		/* TLINT */
	MARITH|MIND,		/* TLUINT */
	MARITH|MIND,		/* TINT */
	MARITH|MIND,		/* TUINT */
	MARITH|MIND,		/* TSINT */
	MARITH|MIND,		/* TSUINT */
	MARITH|MIND,		/* TCHAR */
	MARITH|MIND,		/* TFLOAT */
	MARITH|MIND,		/* TIND */
	0,			/* TCHANNEL */
	0,			/* TARRAY */
	0,			/* TAGGREGATE */
	0,			/* TUNION */
	0,			/* TFUNC */
	0,			/* TVOID */
	0,			/* TADT */
	0,			/* TPOLY */
};

ulong
typeasand[Ntype] =
{
	0,			/* TXXX */
	MARITH,			/* TLINT */
	MARITH,			/* TLUINT */
	MARITH,			/* TINT */
	MARITH,			/* TUINT */
	MARITH,			/* TSINT */
	MARITH,			/* TSUINT */
	MARITH,			/* TCHAR */
	0,			/* TFLOAT */
	0,			/* TIND */
	0,			/* TCHANNEL */
	0,			/* TARRAY */
	0,			/* TAGGREGATE */
	0,			/* TUNION */
	0,			/* TFUNC */
	0,			/* TVOID */
	0,			/* TADT */
	0,			/* TPOLY */
};
