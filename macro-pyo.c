
#define WSIZE 4             //
#define DSIZE 8             //
#define CHUNKSIZE (1 << 12) // (이진수로 0001을 왼쪽으로 12비트만큼 이동 시킴 = 2^12와 동일)

#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define PACK(size, alloc) ((size) | (alloc))

#define GET(p) (*(unsigned int *)(p))
#define PUT(p, val) (*(unsigned int *)(p))