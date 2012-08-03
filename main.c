#include "stdio.h"
#include "stdlib.h"

typedef struct _LinkNode {
  char Value[1000];
  struct _LinkNode * pNext;
} LinkNode;

int InitLinkNode (LinkNode * pNode) {
  int i = -1;

  if (pNode == 0) {
    return 1;
  }

  while (++i < 1000) {
    pNode -> Value [i] = '\0';
  }
  pNode -> pNext = 0;

  return 0;  
}

int FreeLinkNode (LinkNode * pNode) {
  LinkNode * pHead = 0;
  LinkNode * pTail = 0;
  pHead = pNode;
  while (pHead != 0) {
    pTail = pHead -> pNext;
    free (pHead);
    pHead = pTail;
  }
  pNode = 0;

  return 0;
}

int PrintLinkNode (LinkNode * pNode) {
  LinkNode * pHead = pNode;
  while (pHead != 0) {
    printf ("%s -> ", pHead -> Value);
    pHead = pHead -> pNext;
  }

  return 0;
}

LinkNode * SwitchLinkNode (LinkNode * pNode) {
  LinkNode * pFirst = 0;
  LinkNode * pSecond = 0;
  LinkNode * pThird = 0;
  LinkNode * pPrevious = 0;

  if (pNode == 0) return 0;

  pFirst = pNode;
  pNode = 0;
  while (pFirst != 0) {
    pSecond = pFirst -> pNext;
    pThird = pSecond -> pNext;
    pFirst -> pNext = pThird;
    pSecond -> pNext = pFirst;

    if (pPrevious != 0) {
      pPrevious -> pNext = pSecond;
    }

    if (pNode == 0) {
      pNode = pSecond;
    }

    pPrevious = pFirst;

    pFirst = pThird;
  }

  return pNode;
}

int main (int argc, char * argv[]) {
  char nodes[1024] = {'\0'};
  char * pChar = 0;
  LinkNode * pHead = 0;
  LinkNode * pTail = 0;

  int i = -1;
  int j = -1;
  while (++i < argc) {
    int k = -1;
    LinkNode * pNode = 0;
    pNode = malloc (sizeof (LinkNode));
    InitLinkNode (pNode);
    
    pChar = argv[i];
    while (* pChar != '\0') {
      nodes[++j] = * pChar;
      pNode -> Value[++k] = * pChar;
      ++pChar;
    }

    nodes[++j] = ' ';
    pNode -> Value[++k] = '\0';

    if (pHead == 0) {
      pHead = pNode;
    }
    if (pTail == 0) {
      pTail = pNode;
    } else {
      pTail -> pNext = pNode;
      pTail = pNode;
    }
  }

  printf ("nodes string: %s\n\r", nodes);

  PrintLinkNode (pHead);
  printf ("%s\n\r");

  pHead = SwitchLinkNode (pHead);

  PrintLinkNode (pHead);
  printf ("%s\n\r");

  FreeLinkNode (pHead);

  return 0;
}
