#pragma once

namespace MForeach {
    template < typename List >
    typename List::const_iterator const_iterator(List& L) { return List::const_iterator(); }
    template < typename List >
    typename List::const_iterator const_iterator(List* L) { return List::const_iterator(); }
    template < typename List >
    typename List::const_iterator begin(List& L) { return L.begin(); }
    template < typename List >
    typename List::const_iterator end(List& L) { return L.end(); }
    template < typename List >
    typename List::const_iterator begin(List* L) { return L->begin(); }
    template < typename List >
    typename List::const_iterator end(List* L) { return L->end(); }
}

#define foreach(VAR, COL) \
for(__typeof MForeach::const_iterator(COL) __next = MForeach::begin(COL); __next != MForeach::end(COL); ) \
    for(bool __b = true; __b; __b = false) \
        for(VAR = *__next++; __b; __b = false)
