/**
 ** \file misc/unique.hxx
 ** \brief Inline implementation of misc::unique.
 */

#pragma once

#include <misc/contract.hh>
#include <misc/unique.hh>

namespace misc
{
  template <typename T, class C>
  unique<T, C>::unique(const data_type& s)
    // FIXED: Some code was deleted here (Initializations).
    : obj_(&(*object_set_instance().insert(s).first))
  /** \brief Following the Flyweight design pattern, set the attribute to a
       unique reference of value s. You might want to check out std::set methods
       on cppreference.com. */
  {}

  template <typename T, class C>
  typename unique<T, C>::object_set_type& unique<T, C>::object_set_instance()
  {
    // FIXED: Some code was deleted here (Classical Singleton pattern, a la Scott Meyers').
    static object_set_type* set = nullptr;
    if (set == nullptr)
      set = new object_set_type();

    return *set;
    /** \brief Create a persistent instance of a set which would hold each value. */
  }

  template <typename T, class C>
  typename unique<T, C>::object_size_type unique<T, C>::object_map_size()
  {
    // FIXED: Some code was deleted here.
    return object_set_instance().size();
  }

  template <typename T, class C>
  inline const typename unique<T, C>::data_type& unique<T, C>::get() const
  {
    // FIXED: Some code was deleted here.
    return *obj_;
  }

  template <typename T, class C>
  inline unique<T, C>::operator const data_type&() const
  {
    // FIXED: Some code was deleted here (Check Typecasts overload).
    return get();
  }

  template <typename T, class C>
  inline typename unique<T, C>::value_type&
  unique<T, C>::operator=(const value_type& rhs)
  {
    if (this != &rhs)
      obj_ = rhs.obj_;
    return *this;
  }

  template <typename T, class C>
  inline bool unique<T, C>::operator==(const value_type& rhs) const
  {
    return obj_ == rhs.obj_;
  }

  template <typename T, class C>
  inline bool unique<T, C>::operator!=(const value_type& rhs) const
  {
    return !operator==(rhs);
  }

  template <typename T, class C>
  inline bool unique<T, C>::operator<(const value_type& rhs) const
  {
    C cmp;
    assertion(obj_);
    assertion(rhs.obj_);
    return cmp(*obj_, *rhs.obj_);
  }

  template <typename T, class C>
  inline std::ostream& operator<<(std::ostream& ostr, const unique<T, C>& the)
  {
    return ostr << the.get();
  }

} // namespace misc
