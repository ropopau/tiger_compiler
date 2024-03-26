/** \file misc/scoped-map.hxx
 ** \brief Implementation of misc::scoped_map.
 */

#pragma once

#include <sstream>
#include <stdexcept>
#include <type_traits>

#include <ranges>
#include <misc/algorithm.hh>
#include <misc/contract.hh>
#include <misc/indent.hh>
#include <stack>

namespace misc
{
  // FIXME: Some code was deleted here.

  template <typename Key, typename Data>
  void scoped_map<Key,Data>::put(const Key& key, const Data& value)
  {
    if (this->stack_.empty())
    {
      throw std::runtime_error("Stack de scopes vides \n");
    }
    this->stack_.top().insert_or_assign(key,value);
  }

  template <typename Key, typename Data> 
  Data scoped_map<Key,Data>::get(const Key& key) const requires (!IsPointer<Key,Data>)
  {
 
      if(stack_.top().contain(key))       // Element found
      {
        Data res = stack_.top().find(key); 
        return res;       
      }

    throw std::range_error();  // Element not found

  }


  template <typename Key, typename Data>
  Data scoped_map<Key,Data>::get(const Key& key) const requires IsPointer<Key,Data>
  {
      if(stack_.top().contain(key))       // Element found
      {
        Data res = stack_.top().find(key); 
        return res;       
      }
      return nullptr;  // Element not found

  }

  template <typename Key, typename Data>
  std::ostream& scoped_map<Key,Data>::dump(std::ostream& ostr) const
  {
    std::stack<std::map<Key,Data>> temp = std::stack<std::map<Key,Data>>(); 

    while(stack_.size()!= 0)
    {
      temp.push(stack_.pop());
      ostr << "{\n";
      for(const auto& map : temp.top())
      {
          ostr << "key: " << map.first << " --> value: " << map.second << "\n";
      }
      ostr << "}\n";
    }

    
    while(temp.size() != 0)
    {
      stack_.push(temp.pop());
    }


    return ostr;
  }

  template <typename Key, typename Data>
  void scoped_map<Key,Data>::scope_begin()
  {
    std::map<Key,Data> new_map = std::map<Key,Data>();

    for(auto map : stack_.top())
    {
      new_map.insert(map.first,map.second);

    }
    stack_.push(new_map);
  }

  template <typename Key, typename Data>
  void scoped_map<Key,Data>::scope_end()
  {
    stack_.pop();
  }

  template <typename Key, typename Data>
  inline std::ostream& operator<<(std::ostream& ostr,
                                  const scoped_map<Key, Data>& tbl)
  {
    return tbl.dump(ostr);
  }

} // namespace misc
