#ifndef _UntitledGfx_c
#define _UntitledGfx_c


#ifndef _GFX_BITMAP_DATA
#define _GFX_BITMAP_DATA
/* structure with bitmap data */
typedef struct GFX_BITMAP_DATA
{
  char * BitmapIdentifier;
  int BitmapWidth;
  int BitmapHeight;
  int TileWidth;
  int TileHeight;
  int TileCountX;
  int TileCountY;
  int TransparentX;
  int TransparentY;
  int Sequences;
  int ** SequenceData;
  int * SequenceLength;
  int * SequencePosition;
  int * SequenceCounter;

} GFX_BITMAP_DATA;
#endif


#ifndef _GFX_EMPTY
#define _GFX_EMPTY
static int Empty[] = {0};
#endif


/* tile sequences */

int Tiles1SeqLength[] =
{
  -1
};

int Tiles1SeqPosition[0 + 1];
int Tiles1SeqCounter[0 + 1];

int * Tiles1Sequences[] = 
{
  Empty
};



/* tile sequences */

int Tiles2SeqLength[] =
{
  -1
};

int Tiles2SeqPosition[0 + 1];
int Tiles2SeqCounter[0 + 1];

int * Tiles2Sequences[] = 
{
  Empty
};

 

/* bitmap data */
const struct GFX_BITMAP_DATA GfxTiles1Bitmap = 
  { "Tiles1",  