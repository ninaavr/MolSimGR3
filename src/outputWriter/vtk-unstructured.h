// Copyright (c) 2005-2014 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

#ifndef VTK_UNSTRUCTURED_HXX
#define VTK_UNSTRUCTURED_HXX

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_TREE_USE_CHAR
#define XSD_CXX_TREE_USE_CHAR
#endif

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 4000000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/types.hxx>

#include <xsd/cxx/xml/error-handler.hxx>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

#include <xsd/cxx/tree/parsing.hxx>
#include <xsd/cxx/tree/parsing/byte.hxx>
#include <xsd/cxx/tree/parsing/unsigned-byte.hxx>
#include <xsd/cxx/tree/parsing/short.hxx>
#include <xsd/cxx/tree/parsing/unsigned-short.hxx>
#include <xsd/cxx/tree/parsing/int.hxx>
#include <xsd/cxx/tree/parsing/unsigned-int.hxx>
#include <xsd/cxx/tree/parsing/long.hxx>
#include <xsd/cxx/tree/parsing/unsigned-long.hxx>
#include <xsd/cxx/tree/parsing/boolean.hxx>
#include <xsd/cxx/tree/parsing/float.hxx>
#include <xsd/cxx/tree/parsing/double.hxx>
#include <xsd/cxx/tree/parsing/decimal.hxx>

#include <xsd/cxx/xml/dom/serialization-header.hxx>
#include <xsd/cxx/tree/serialization.hxx>
#include <xsd/cxx/tree/serialization/byte.hxx>
#include <xsd/cxx/tree/serialization/unsigned-byte.hxx>
#include <xsd/cxx/tree/serialization/short.hxx>
#include <xsd/cxx/tree/serialization/unsigned-short.hxx>
#include <xsd/cxx/tree/serialization/int.hxx>
#include <xsd/cxx/tree/serialization/unsigned-int.hxx>
#include <xsd/cxx/tree/serialization/long.hxx>
#include <xsd/cxx/tree/serialization/unsigned-long.hxx>
#include <xsd/cxx/tree/serialization/boolean.hxx>
#include <xsd/cxx/tree/serialization/float.hxx>
#include <xsd/cxx/tree/serialization/double.hxx>
#include <xsd/cxx/tree/serialization/decimal.hxx>

namespace xml_schema
{
  // anyType and anySimpleType.
  //
  typedef ::xsd::cxx::tree::type type;
  typedef ::xsd::cxx::tree::simple_type< char, type > simple_type;
  typedef ::xsd::cxx::tree::type container;

  // 8-bit
  //
  typedef signed char byte;
  typedef unsigned char unsigned_byte;

  // 16-bit
  //
  typedef short short_;
  typedef unsigned short unsigned_short;

  // 32-bit
  //
  typedef int int_;
  typedef unsigned int unsigned_int;

  // 64-bit
  //
  typedef long long long_;
  typedef unsigned long long unsigned_long;

  // Supposed to be arbitrary-length integral types.
  //
  typedef long long integer;
  typedef long long non_positive_integer;
  typedef unsigned long long non_negative_integer;
  typedef unsigned long long positive_integer;
  typedef long long negative_integer;

  // Boolean.
  //
  typedef bool boolean;

  // Floating-point types.
  //
  typedef float float_;
  typedef double double_;
  typedef double decimal;

  // String types.
  //
  typedef ::xsd::cxx::tree::string< char, simple_type > string;
  typedef ::xsd::cxx::tree::normalized_string< char, string > normalized_string;
  typedef ::xsd::cxx::tree::token< char, normalized_string > token;
  typedef ::xsd::cxx::tree::name< char, token > name;
  typedef ::xsd::cxx::tree::nmtoken< char, token > nmtoken;
  typedef ::xsd::cxx::tree::nmtokens< char, simple_type, nmtoken > nmtokens;
  typedef ::xsd::cxx::tree::ncname< char, name > ncname;
  typedef ::xsd::cxx::tree::language< char, token > language;

  // ID/IDREF.
  //
  typedef ::xsd::cxx::tree::id< char, ncname > id;
  typedef ::xsd::cxx::tree::idref< char, ncname, type > idref;
  typedef ::xsd::cxx::tree::idrefs< char, simple_type, idref > idrefs;

  // URI.
  //
  typedef ::xsd::cxx::tree::uri< char, simple_type > uri;

  // Qualified name.
  //
  typedef ::xsd::cxx::tree::qname< char, simple_type, uri, ncname > qname;

  // Binary.
  //
  typedef ::xsd::cxx::tree::buffer< char > buffer;
  typedef ::xsd::cxx::tree::base64_binary< char, simple_type > base64_binary;
  typedef ::xsd::cxx::tree::hex_binary< char, simple_type > hex_binary;

  // Date/time.
  //
  typedef ::xsd::cxx::tree::time_zone time_zone;
  typedef ::xsd::cxx::tree::date< char, simple_type > date;
  typedef ::xsd::cxx::tree::date_time< char, simple_type > date_time;
  typedef ::xsd::cxx::tree::duration< char, simple_type > duration;
  typedef ::xsd::cxx::tree::gday< char, simple_type > gday;
  typedef ::xsd::cxx::tree::gmonth< char, simple_type > gmonth;
  typedef ::xsd::cxx::tree::gmonth_day< char, simple_type > gmonth_day;
  typedef ::xsd::cxx::tree::gyear< char, simple_type > gyear;
  typedef ::xsd::cxx::tree::gyear_month< char, simple_type > gyear_month;
  typedef ::xsd::cxx::tree::time< char, simple_type > time;

  // Entity.
  //
  typedef ::xsd::cxx::tree::entity< char, ncname > entity;
  typedef ::xsd::cxx::tree::entities< char, simple_type, entity > entities;

  typedef ::xsd::cxx::tree::content_order content_order;
  // Namespace information and list stream. Used in
  // serialization functions.
  //
  typedef ::xsd::cxx::xml::dom::namespace_info< char > namespace_info;
  typedef ::xsd::cxx::xml::dom::namespace_infomap< char > namespace_infomap;
  typedef ::xsd::cxx::tree::list_stream< char > list_stream;
  typedef ::xsd::cxx::tree::as_double< double_ > as_double;
  typedef ::xsd::cxx::tree::as_decimal< decimal > as_decimal;
  typedef ::xsd::cxx::tree::facet facet;

  // Flags and properties.
  //
  typedef ::xsd::cxx::tree::flags flags;
  typedef ::xsd::cxx::tree::properties< char > properties;

  // Parsing/serialization diagnostics.
  //
  typedef ::xsd::cxx::tree::severity severity;
  typedef ::xsd::cxx::tree::error< char > error;
  typedef ::xsd::cxx::tree::diagnostics< char > diagnostics;

  // Exceptions.
  //
  typedef ::xsd::cxx::tree::exception< char > exception;
  typedef ::xsd::cxx::tree::bounds< char > bounds;
  typedef ::xsd::cxx::tree::duplicate_id< char > duplicate_id;
  typedef ::xsd::cxx::tree::parsing< char > parsing;
  typedef ::xsd::cxx::tree::expected_element< char > expected_element;
  typedef ::xsd::cxx::tree::unexpected_element< char > unexpected_element;
  typedef ::xsd::cxx::tree::expected_attribute< char > expected_attribute;
  typedef ::xsd::cxx::tree::unexpected_enumerator< char > unexpected_enumerator;
  typedef ::xsd::cxx::tree::expected_text_content< char > expected_text_content;
  typedef ::xsd::cxx::tree::no_prefix_mapping< char > no_prefix_mapping;
  typedef ::xsd::cxx::tree::serialization< char > serialization;

  // Error handler callback interface.
  //
  typedef ::xsd::cxx::xml::error_handler< char > error_handler;

  // DOM interaction.
  //
  namespace dom
  {
    // Automatic pointer for DOMDocument.
    //
    using ::xsd::cxx::xml::dom::auto_ptr;

#ifndef XSD_CXX_TREE_TREE_NODE_KEY__XML_SCHEMA
#define XSD_CXX_TREE_TREE_NODE_KEY__XML_SCHEMA
    // DOM user data key for back pointers to tree nodes.
    //
    const XMLCh* const tree_node_key = ::xsd::cxx::tree::user_data_keys::node;
#endif
  }
}

// Forward declarations.
//
class DataArrayList_t;
class DataArray_t;
class PieceUnstructuredGrid_t;
class UnstructuredGrid_t;
class PolyData_t;
class VTKFile_t;
class type;
class PointData;
class CellData;
class Points;
class Cells;

#include <memory>    // ::std::auto_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

class DataArrayList_t: public ::xml_schema::simple_type,
  public ::xsd::cxx::tree::list< ::xml_schema::decimal, char, ::xsd::cxx::tree::schema_type::decimal >
{
  public:
  DataArrayList_t ();

  DataArrayList_t (size_type n, const ::xml_schema::decimal& x);

  template < typename I >
  DataArrayList_t (const I& begin, const I& end)
  : ::xsd::cxx::tree::list< ::xml_schema::decimal, char, ::xsd::cxx::tree::schema_type::decimal > (begin, end, this)
  {
  }

  DataArrayList_t (const ::xercesc::DOMElement& e,
                   ::xml_schema::flags f = 0,
                   ::xml_schema::container* c = 0);

  DataArrayList_t (const ::xercesc::DOMAttr& a,
                   ::xml_schema::flags f = 0,
                   ::xml_schema::container* c = 0);

  DataArrayList_t (const ::std::string& s,
                   const ::xercesc::DOMElement* e,
                   ::xml_schema::flags f = 0,
                   ::xml_schema::container* c = 0);

  DataArrayList_t (const DataArrayList_t& x,
                   ::xml_schema::flags f = 0,
                   ::xml_schema::container* c = 0);

  virtual DataArrayList_t*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  virtual 
  ~DataArrayList_t ();
};

class DataArray_t: public ::DataArrayList_t
{
  public:
  // type
  //
  typedef ::type type_type;
  typedef ::xsd::cxx::tree::traits< type_type, char > type_traits;

  const type_type&
  type () const;

  type_type&
  type ();

  void
  type (const type_type& x);

  void
  type (::std::auto_ptr< type_type > p);

  // Name
  //
  typedef ::xml_schema::string Name_type;
  typedef ::xsd::cxx::tree::traits< Name_type, char > Name_traits;

  const Name_type&
  Name () const;

  Name_type&
  Name ();

  void
  Name (const Name_type& x);

  void
  Name (::std::auto_ptr< Name_type > p);

  // NumberOfComponents
  //
  typedef ::xml_schema::integer NumberOfComponents_type;
  typedef ::xsd::cxx::tree::traits< NumberOfComponents_type, char > NumberOfComponents_traits;

  const NumberOfComponents_type&
  NumberOfComponents () const;

  NumberOfComponents_type&
  NumberOfComponents ();

  void
  NumberOfComponents (const NumberOfComponents_type& x);

  // format
  //
  typedef ::xml_schema::string format_type;
  typedef ::xsd::cxx::tree::traits< format_type, char > format_traits;

  const format_type&
  format () const;

  static const format_type&
  format_default_value ();

  // offset
  //
  typedef ::xml_schema::integer offset_type;
  typedef ::xsd::cxx::tree::optional< offset_type > offset_optional;
  typedef ::xsd::cxx::tree::traits< offset_type, char > offset_traits;

  const offset_optional&
  offset () const;

  offset_optional&
  offset ();

  void
  offset (const offset_type& x);

  void
  offset (const offset_optional& x);

  // Constructors.
  //
  DataArray_t (const type_type&,
               const Name_type&,
               const NumberOfComponents_type&);

  DataArray_t (const ::DataArrayList_t&,
               const type_type&,
               const Name_type&,
               const NumberOfComponents_type&);

  DataArray_t (const ::xercesc::DOMElement& e,
               ::xml_schema::flags f = 0,
               ::xml_schema::container* c = 0);

  DataArray_t (const DataArray_t& x,
               ::xml_schema::flags f = 0,
               ::xml_schema::container* c = 0);

  virtual DataArray_t*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  DataArray_t&
  operator= (const DataArray_t& x);

  virtual 
  ~DataArray_t ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  ::xsd::cxx::tree::one< type_type > type_;
  ::xsd::cxx::tree::one< Name_type > Name_;
  ::xsd::cxx::tree::one< NumberOfComponents_type > NumberOfComponents_;
  ::xsd::cxx::tree::one< format_type > format_;
  static const format_type format_default_value_;
  offset_optional offset_;
};

class PieceUnstructuredGrid_t: public ::xml_schema::type
{
  public:
  // PointData
  //
  typedef ::PointData PointData_type;
  typedef ::xsd::cxx::tree::traits< PointData_type, char > PointData_traits;

  const PointData_type&
  PointData () const;

  PointData_type&
  PointData ();

  void
  PointData (const PointData_type& x);

  void
  PointData (::std::auto_ptr< PointData_type > p);

  // CellData
  //
  typedef ::CellData CellData_type;
  typedef ::xsd::cxx::tree::traits< CellData_type, char > CellData_traits;

  const CellData_type&
  CellData () const;

  CellData_type&
  CellData ();

  void
  CellData (const CellData_type& x);

  void
  CellData (::std::auto_ptr< CellData_type > p);

  // Points
  //
  typedef ::Points Points_type;
  typedef ::xsd::cxx::tree::traits< Points_type, char > Points_traits;

  const Points_type&
  Points () const;

  Points_type&
  Points ();

  void
  Points (const Points_type& x);

  void
  Points (::std::auto_ptr< Points_type > p);

  // Cells
  //
  typedef ::Cells Cells_type;
  typedef ::xsd::cxx::tree::traits< Cells_type, char > Cells_traits;

  const Cells_type&
  Cells () const;

  Cells_type&
  Cells ();

  void
  Cells (const Cells_type& x);

  void
  Cells (::std::auto_ptr< Cells_type > p);

  // NumberOfPoints
  //
  typedef ::xml_schema::integer NumberOfPoints_type;
  typedef ::xsd::cxx::tree::traits< NumberOfPoints_type, char > NumberOfPoints_traits;

  const NumberOfPoints_type&
  NumberOfPoints () const;

  NumberOfPoints_type&
  NumberOfPoints ();

  void
  NumberOfPoints (const NumberOfPoints_type& x);

  // NumberOfCells
  //
  typedef ::xml_schema::integer NumberOfCells_type;
  typedef ::xsd::cxx::tree::traits< NumberOfCells_type, char > NumberOfCells_traits;

  const NumberOfCells_type&
  NumberOfCells () const;

  NumberOfCells_type&
  NumberOfCells ();

  void
  NumberOfCells (const NumberOfCells_type& x);

  // Constructors.
  //
  PieceUnstructuredGrid_t (const PointData_type&,
                           const CellData_type&,
                           const Points_type&,
                           const Cells_type&,
                           const NumberOfPoints_type&,
                           const NumberOfCells_type&);

  PieceUnstructuredGrid_t (::std::auto_ptr< PointData_type >,
                           ::std::auto_ptr< CellData_type >,
                           ::std::auto_ptr< Points_type >,
                           ::std::auto_ptr< Cells_type >,
                           const NumberOfPoints_type&,
                           const NumberOfCells_type&);

  PieceUnstructuredGrid_t (const ::xercesc::DOMElement& e,
                           ::xml_schema::flags f = 0,
                           ::xml_schema::container* c = 0);

  PieceUnstructuredGrid_t (const PieceUnstructuredGrid_t& x,
                           ::xml_schema::flags f = 0,
                           ::xml_schema::container* c = 0);

  virtual PieceUnstructuredGrid_t*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  PieceUnstructuredGrid_t&
  operator= (const PieceUnstructuredGrid_t& x);

  virtual 
  ~PieceUnstructuredGrid_t ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  ::xsd::cxx::tree::one< PointData_type > PointData_;
  ::xsd::cxx::tree::one< CellData_type > CellData_;
  ::xsd::cxx::tree::one< Points_type > Points_;
  ::xsd::cxx::tree::one< Cells_type > Cells_;
  ::xsd::cxx::tree::one< NumberOfPoints_type > NumberOfPoints_;
  ::xsd::cxx::tree::one< NumberOfCells_type > NumberOfCells_;
};

class UnstructuredGrid_t: public ::xml_schema::type
{
  public:
  // Piece
  //
  typedef ::PieceUnstructuredGrid_t Piece_type;
  typedef ::xsd::cxx::tree::traits< Piece_type, char > Piece_traits;

  const Piece_type&
  Piece () const;

  Piece_type&
  Piece ();

  void
  Piece (const Piece_type& x);

  void
  Piece (::std::auto_ptr< Piece_type > p);

  // Constructors.
  //
  UnstructuredGrid_t (const Piece_type&);

  UnstructuredGrid_t (::std::auto_ptr< Piece_type >);

  UnstructuredGrid_t (const ::xercesc::DOMElement& e,
                      ::xml_schema::flags f = 0,
                      ::xml_schema::container* c = 0);

  UnstructuredGrid_t (const UnstructuredGrid_t& x,
                      ::xml_schema::flags f = 0,
                      ::xml_schema::container* c = 0);

  virtual UnstructuredGrid_t*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  UnstructuredGrid_t&
  operator= (const UnstructuredGrid_t& x);

  virtual 
  ~UnstructuredGrid_t ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  ::xsd::cxx::tree::one< Piece_type > Piece_;
};

class PolyData_t: public ::xml_schema::type
{
  public:
  // greeting
  //
  typedef ::xml_schema::string greeting_type;
  typedef ::xsd::cxx::tree::traits< greeting_type, char > greeting_traits;

  const greeting_type&
  greeting () const;

  greeting_type&
  greeting ();

  void
  greeting (const greeting_type& x);

  void
  greeting (::std::auto_ptr< greeting_type > p);

  // Constructors.
  //
  PolyData_t (const greeting_type&);

  PolyData_t (const ::xercesc::DOMElement& e,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

  PolyData_t (const PolyData_t& x,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

  virtual PolyData_t*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  PolyData_t&
  operator= (const PolyData_t& x);

  virtual 
  ~PolyData_t ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  ::xsd::cxx::tree::one< greeting_type > greeting_;
};

class VTKFile_t: public ::xml_schema::type
{
  public:
  // UnstructuredGrid
  //
  typedef ::UnstructuredGrid_t UnstructuredGrid_type;
  typedef ::xsd::cxx::tree::optional< UnstructuredGrid_type > UnstructuredGrid_optional;
  typedef ::xsd::cxx::tree::traits< UnstructuredGrid_type, char > UnstructuredGrid_traits;

  const UnstructuredGrid_optional&
  UnstructuredGrid () const;

  UnstructuredGrid_optional&
  UnstructuredGrid ();

  void
  UnstructuredGrid (const UnstructuredGrid_type& x);

  void
  UnstructuredGrid (const UnstructuredGrid_optional& x);

  void
  UnstructuredGrid (::std::auto_ptr< UnstructuredGrid_type > p);

  // PolyData
  //
  typedef ::PolyData_t PolyData_type;
  typedef ::xsd::cxx::tree::optional< PolyData_type > PolyData_optional;
  typedef ::xsd::cxx::tree::traits< PolyData_type, char > PolyData_traits;

  const PolyData_optional&
  PolyData () const;

  PolyData_optional&
  PolyData ();

  void
  PolyData (const PolyData_type& x);

  void
  PolyData (const PolyData_optional& x);

  void
  PolyData (::std::auto_ptr< PolyData_type > p);

  // type
  //
  typedef ::xml_schema::string type_type;
  typedef ::xsd::cxx::tree::traits< type_type, char > type_traits;

  const type_type&
  type () const;

  type_type&
  type ();

  void
  type (const type_type& x);

  void
  type (::std::auto_ptr< type_type > p);

  // version
  //
  typedef ::xml_schema::string version_type;
  typedef ::xsd::cxx::tree::traits< version_type, char > version_traits;

  const version_type&
  version () const;

  static const version_type&
  version_default_value ();

  // byte_order
  //
  typedef ::xml_schema::string byte_order_type;
  typedef ::xsd::cxx::tree::traits< byte_order_type, char > byte_order_traits;

  const byte_order_type&
  byte_order () const;

  static const byte_order_type&
  byte_order_default_value ();

  // Constructors.
  //
  VTKFile_t (const type_type&);

  VTKFile_t (const ::xercesc::DOMElement& e,
             ::xml_schema::flags f = 0,
             ::xml_schema::container* c = 0);

  VTKFile_t (const VTKFile_t& x,
             ::xml_schema::flags f = 0,
             ::xml_schema::container* c = 0);

  virtual VTKFile_t*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  VTKFile_t&
  operator= (const VTKFile_t& x);

  virtual 
  ~VTKFile_t ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  UnstructuredGrid_optional UnstructuredGrid_;
  PolyData_optional PolyData_;
  ::xsd::cxx::tree::one< type_type > type_;
  ::xsd::cxx::tree::one< version_type > version_;
  static const version_type version_default_value_;
  ::xsd::cxx::tree::one< byte_order_type > byte_order_;
  static const byte_order_type byte_order_default_value_;
};

class type: public ::xml_schema::string
{
  public:
  enum value
  {
    Int8,
    UInt8,
    Int16,
    UInt16,
    Int32,
    UInt32,
    Int64,
    UInt64,
    Float32,
    Float64
  };

  type (value v);

  type (const char* v);

  type (const ::std::string& v);

  type (const ::xml_schema::string& v);

  type (const ::xercesc::DOMElement& e,
        ::xml_schema::flags f = 0,
        ::xml_schema::container* c = 0);

  type (const ::xercesc::DOMAttr& a,
        ::xml_schema::flags f = 0,
        ::xml_schema::container* c = 0);

  type (const ::std::string& s,
        const ::xercesc::DOMElement* e,
        ::xml_schema::flags f = 0,
        ::xml_schema::container* c = 0);

  type (const type& x,
        ::xml_schema::flags f = 0,
        ::xml_schema::container* c = 0);

  virtual type*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  type&
  operator= (value v);

  virtual
  operator value () const
  {
    return _xsd_type_convert ();
  }

  protected:
  value
  _xsd_type_convert () const;

  public:
  static const char* const _xsd_type_literals_[10];
  static const value _xsd_type_indexes_[10];
};

class PointData: public ::xml_schema::type
{
  public:
  // DataArray
  //
  typedef ::DataArray_t DataArray_type;
  typedef ::xsd::cxx::tree::sequence< DataArray_type > DataArray_sequence;
  typedef DataArray_sequence::iterator DataArray_iterator;
  typedef DataArray_sequence::const_iterator DataArray_const_iterator;
  typedef ::xsd::cxx::tree::traits< DataArray_type, char > DataArray_traits;

  const DataArray_sequence&
  DataArray () const;

  DataArray_sequence&
  DataArray ();

  void
  DataArray (const DataArray_sequence& s);

  // Constructors.
  //
  PointData ();

  PointData (const ::xercesc::DOMElement& e,
             ::xml_schema::flags f = 0,
             ::xml_schema::container* c = 0);

  PointData (const PointData& x,
             ::xml_schema::flags f = 0,
             ::xml_schema::container* c = 0);

  virtual PointData*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  PointData&
  operator= (const PointData& x);

  virtual 
  ~PointData ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  DataArray_sequence DataArray_;
};

class CellData: public ::xml_schema::type
{
  public:
  // DataArray
  //
  typedef ::DataArray_t DataArray_type;
  typedef ::xsd::cxx::tree::sequence< DataArray_type > DataArray_sequence;
  typedef DataArray_sequence::iterator DataArray_iterator;
  typedef DataArray_sequence::const_iterator DataArray_const_iterator;
  typedef ::xsd::cxx::tree::traits< DataArray_type, char > DataArray_traits;

  const DataArray_sequence&
  DataArray () const;

  DataArray_sequence&
  DataArray ();

  void
  DataArray (const DataArray_sequence& s);

  // Constructors.
  //
  CellData ();

  CellData (const ::xercesc::DOMElement& e,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

  CellData (const CellData& x,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

  virtual CellData*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  CellData&
  operator= (const CellData& x);

  virtual 
  ~CellData ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  DataArray_sequence DataArray_;
};

class Points: public ::xml_schema::type
{
  public:
  // DataArray
  //
  typedef ::DataArray_t DataArray_type;
  typedef ::xsd::cxx::tree::sequence< DataArray_type > DataArray_sequence;
  typedef DataArray_sequence::iterator DataArray_iterator;
  typedef DataArray_sequence::const_iterator DataArray_const_iterator;
  typedef ::xsd::cxx::tree::traits< DataArray_type, char > DataArray_traits;

  const DataArray_sequence&
  DataArray () const;

  DataArray_sequence&
  DataArray ();

  void
  DataArray (const DataArray_sequence& s);

  // Constructors.
  //
  Points ();

  Points (const ::xercesc::DOMElement& e,
          ::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0);

  Points (const Points& x,
          ::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0);

  virtual Points*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  Points&
  operator= (const Points& x);

  virtual 
  ~Points ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  DataArray_sequence DataArray_;
};

class Cells: public ::xml_schema::type
{
  public:
  // DataArray
  //
  typedef ::DataArray_t DataArray_type;
  typedef ::xsd::cxx::tree::sequence< DataArray_type > DataArray_sequence;
  typedef DataArray_sequence::iterator DataArray_iterator;
  typedef DataArray_sequence::const_iterator DataArray_const_iterator;
  typedef ::xsd::cxx::tree::traits< DataArray_type, char > DataArray_traits;

  const DataArray_sequence&
  DataArray () const;

  DataArray_sequence&
  DataArray ();

  void
  DataArray (const DataArray_sequence& s);

  // Constructors.
  //
  Cells ();

  Cells (const ::xercesc::DOMElement& e,
         ::xml_schema::flags f = 0,
         ::xml_schema::container* c = 0);

  Cells (const Cells& x,
         ::xml_schema::flags f = 0,
         ::xml_schema::container* c = 0);

  virtual Cells*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  Cells&
  operator= (const Cells& x);

  virtual 
  ~Cells ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  DataArray_sequence DataArray_;
};

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

// Parse a URI or a local file.
//

::std::auto_ptr< ::VTKFile_t >
VTKFile (const ::std::string& uri,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::VTKFile_t >
VTKFile (const ::std::string& uri,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::VTKFile_t >
VTKFile (const ::std::string& uri,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse std::istream.
//

::std::auto_ptr< ::VTKFile_t >
VTKFile (::std::istream& is,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::VTKFile_t >
VTKFile (::std::istream& is,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::VTKFile_t >
VTKFile (::std::istream& is,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::VTKFile_t >
VTKFile (::std::istream& is,
         const ::std::string& id,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::VTKFile_t >
VTKFile (::std::istream& is,
         const ::std::string& id,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::VTKFile_t >
VTKFile (::std::istream& is,
         const ::std::string& id,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::InputSource.
//

::std::auto_ptr< ::VTKFile_t >
VTKFile (::xercesc::InputSource& is,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::VTKFile_t >
VTKFile (::xercesc::InputSource& is,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::VTKFile_t >
VTKFile (::xercesc::InputSource& is,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::DOMDocument.
//

::std::auto_ptr< ::VTKFile_t >
VTKFile (const ::xercesc::DOMDocument& d,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::VTKFile_t >
VTKFile (::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

#include <iosfwd>

#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/framework/XMLFormatter.hpp>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

void
operator<< (::xercesc::DOMElement&, const DataArrayList_t&);

void
operator<< (::xercesc::DOMAttr&, const DataArrayList_t&);

void
operator<< (::xml_schema::list_stream&,
            const DataArrayList_t&);

void
operator<< (::xercesc::DOMElement&, const DataArray_t&);

void
operator<< (::xercesc::DOMElement&, const PieceUnstructuredGrid_t&);

void
operator<< (::xercesc::DOMElement&, const UnstructuredGrid_t&);

void
operator<< (::xercesc::DOMElement&, const PolyData_t&);

void
operator<< (::xercesc::DOMElement&, const VTKFile_t&);

// Serialize to std::ostream.
//

void
VTKFile (::std::ostream& os,
         const ::VTKFile_t& x,
         const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
         const ::std::string& e = "UTF-8",
         ::xml_schema::flags f = 0);

void
VTKFile (::std::ostream& os,
         const ::VTKFile_t& x,
         ::xml_schema::error_handler& eh,
         const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
         const ::std::string& e = "UTF-8",
         ::xml_schema::flags f = 0);

void
VTKFile (::std::ostream& os,
         const ::VTKFile_t& x,
         ::xercesc::DOMErrorHandler& eh,
         const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
         const ::std::string& e = "UTF-8",
         ::xml_schema::flags f = 0);

// Serialize to xercesc::XMLFormatTarget.
//

void
VTKFile (::xercesc::XMLFormatTarget& ft,
         const ::VTKFile_t& x,
         const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
         const ::std::string& e = "UTF-8",
         ::xml_schema::flags f = 0);

void
VTKFile (::xercesc::XMLFormatTarget& ft,
         const ::VTKFile_t& x,
         ::xml_schema::error_handler& eh,
         const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
         const ::std::string& e = "UTF-8",
         ::xml_schema::flags f = 0);

void
VTKFile (::xercesc::XMLFormatTarget& ft,
         const ::VTKFile_t& x,
         ::xercesc::DOMErrorHandler& eh,
         const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
         const ::std::string& e = "UTF-8",
         ::xml_schema::flags f = 0);

// Serialize to an existing xercesc::DOMDocument.
//

void
VTKFile (::xercesc::DOMDocument& d,
         const ::VTKFile_t& x,
         ::xml_schema::flags f = 0);

// Serialize to a new xercesc::DOMDocument.
//

::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >
VTKFile (const ::VTKFile_t& x,
         const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
         ::xml_schema::flags f = 0);

void
operator<< (::xercesc::DOMElement&, const type&);

void
operator<< (::xercesc::DOMAttr&, const type&);

void
operator<< (::xml_schema::list_stream&,
            const type&);

void
operator<< (::xercesc::DOMElement&, const PointData&);

void
operator<< (::xercesc::DOMElement&, const CellData&);

void
operator<< (::xercesc::DOMElement&, const Points&);

void
operator<< (::xercesc::DOMElement&, const Cells&);

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // VTK_UNSTRUCTURED_HXX
