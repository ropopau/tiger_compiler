/**
 ** \file misc/scoped-map.hh
 ** \brief Declaration of misc::scoped_map.
 **
 ** This implements a stack of dictionnaries.  Each time a scope is
 ** opened, a new dictionnary is added on the top of the stack; the
 ** dictionary is removed when the scope is closed.  Lookup of keys
 ** is done in the last added dictionnary first (LIFO).
 **
 ** In particular this class is used to implement symbol tables.
 **/

#pragma once

#include <map>
#include <vector>
#include <stack>




namespace misc
{


  template <typename Key, typename Data>
  concept IsPointer = std::is_pointer<Data>::value;



  template <typename Key, typename Data> class scoped_map
  {
    // FIXED
    public:
      
      void put(const Key& key, const Data& value);

      Data get(const Key& key) const requires (!IsPointer<Key,Data>);

      Data get(const Key& key) const requires IsPointer<Key,Data>;

      std::ostream& dump(std::ostream& ostr) const;

      void scope_begin();

      void scope_end();


    private:
      std::stack<std::map<Key,Data>> stack_;
  };

  template <typename Key, typename Data>
  std::ostream& operator<<(std::ostream& ostr,
                           const scoped_map<Key, Data>& tbl);

  // FIXME: Some code was deleted here.




} // namespace misc

#include <misc/scoped-map.hxx>
