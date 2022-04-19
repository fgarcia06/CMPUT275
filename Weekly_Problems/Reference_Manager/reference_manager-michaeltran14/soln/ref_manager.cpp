#include "ref_manager.h"
#include <cassert>

ReferenceManager::ReferenceManager() {
  numToDelete = 0;
  for (int i = 0; i < MAX_PTRS; i++) {
    pointers[i] = NULL;
  }
}

ReferenceManager::~ReferenceManager() {
  for (int i = 0; i < MAX_PTRS; i++){
    reassignPointer(i, NULL); //reassigning all pointers in the array to NULL
  }
  garbageCollect(); //freeing the memory from the heap
}

void ReferenceManager::garbageCollect() {
  for (int i = 0; i < numToDelete; i++){ //for each index in the garbage array, print the content and then deletes it
    cout << garbage[i] << endl;
    delete[] garbage[i];
  }
  numToDelete = 0; //resetting numToDelete counter
}

void ReferenceManager::reassignPointer(unsigned int ptrIndex, const char* newAddr) {
  //making the pointer at ptrIndex in the pointers array reference to newAddr
  
  refCount[pointers[ptrIndex]]--; //decrementing the pointer count
  if (refCount[pointers[ptrIndex]] == 0) { 
    garbage[numToDelete] = pointers[ptrIndex]; //assign garbage array index to the string pointed to by pointers array
    numToDelete += 1;
  }

  pointers[ptrIndex] = newAddr; //set new address
  refCount[pointers[ptrIndex]]++; //increment pointer count of new addr
}

void ReferenceManager::readString(unsigned int ptrIndex, unsigned int length) {
  // c p n str, p = ptrIndex, n = length
  // allocating space for the string length + 1 (for the null terminating character) using new
  char *s_ptr = new char[length+1];
  cin >> s_ptr;

  //null terminating character
  s_ptr[length] = '\0';

  reassignPointer(ptrIndex, s_ptr);
}

const char* ReferenceManager::getPtr(unsigned int ptrIndex) {
  assert(ptrIndex < MAX_PTRS);
  return pointers[ptrIndex];
}
