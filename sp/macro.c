
#define WSIZE 4             //
#define DSIZE 8             //
#define CHUNKSIZE (1 << 12) // (이진수로 0001을 왼쪽으로 12비트만큼 이동 시킴 = 2^12와 동일)

#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define PACK(size, alloc) ((size) | (alloc))

#define GET(p) (*(unsigned int *)(p))
#define PUT(p, val) (*(unsigned int *)(p) = (val))

#define GET_SIZE(p) (GET(p) & ~0x7)
#define GET_ALLOC(p) (GET(p) & 0x1)

// 페이로드의 시작점인 bp에서 헤더의 시작 주소를 알아내는 매크로
// WSIZE는 워드의 크기이자 헤더/푸터의 크기(바이트 단위)로 정의되어 있음.

// 왜 char 포인터?
// 포인터 산술의 특징
// // //  C 언어에서 포인터 연산은 포인터가 가르키는 데이터 타입의 크기에 따라 자동으로 스케일링 됨.
// // //  bp는 void * 타입일 수 있으며, 직접 역참조하거나 산술 연산을 수행하기 위해서는 적절한 타입으로 캐스팅이 되어야 함.
// // //  ((char *)(bp))는
// header는 블록의 크기와 할당 여부 정보를 가지고 있는 메타데이터

#define FTRP(bp) ((char *)(bp) + GET_SIZE(HDRP(bp)) - DSIZE)

// if ((heap_listp = mem_sbrk(4 * WSIZE)) == (void *)-1)
// return -1;

// PUT(heap_listp, 0)
// PUT(heap_listp + (1 * WSIZE), PACK(DSIZE, 1));
// PUT(heap_listp + (2 * WSIZE), PACK(DSIZE, 1));
// PUT(heap_listp + (3 * WSIZE), PACK(DSIZE, 1));
// heap_listp += (2*WSIZE);