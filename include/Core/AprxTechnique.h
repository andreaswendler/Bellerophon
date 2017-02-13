/******************************************************************************
 * @file   AprxTechnique.h
 * @author Antonio Tammaro
 * @date   12 gen 2017
 * @brief  Abstraction of the approximation techniques
 ******************************************************************************/
#ifndef INCLUDE_BELLEROPHON_APRXTECHNIQUE_H_
#define INCLUDE_BELLEROPHON_APRXTECHNIQUE_H_

// LLVM Headers
#include "llvm/Support/raw_ostream.h"
// C/C++ headers
#include <string>
#include <vector>

namespace bellerophon{
namespace core{

// Typedef
using AprxTechniqueIdTy = unsigned;
using AprxGrade = short;

/// \brief Interface that abstracts an approximation strategy.
/// \details It has to be implemented to create a context that is valid for an approximation strategy.
// Specific approximation techniques MUST inherit from this class and define their own context.
class AprxTechnique
{
public:

  // Class ctor 
  AprxTechnique (AprxTechniqueIdTy id): Id(id) {}
  // Virtual dtor
  virtual ~AprxTechnique() { }

  //[>-------------------------------------------------------------------*
  // Get Methods
  //[>-------------------------------------------------------------------*
  AprxTechniqueIdTy getId() const {
      return Id;
  }
  
  //AprxMode getAprxMode() const {
      //return Mode;
  //}
  //*-------------------------------------------------------------------*
  // Set Methods
  //*-------------------------------------------------------------------*
  void setId ( AprxTechniqueIdTy id ) {
      Id = id;
  }
  //*-------------------------------------------------------------------*
  // Functional Methods 
  //*-------------------------------------------------------------------*
  //TODO Check approximation type
  //
  /// \brief Apply an approximation.
  /// \param The approximation grade
  /// \return String vector containing compiler arguments that represent the approximation
  virtual ::std::vector<::std::string> applyApproximation (
      ::bellerophon::core::AprxGrade ) const {
      return ::std::vector<::std::string>();
  }

  /// \brief Apply approximation using the addresses of variables
  virtual void applyApproximation ( ::bellerophon::core::AprxGrade, ::std::vector<uint64_t> ) const =0;


  /// \brief Used with GLOBAL_VALUE_MODIFICATION approximation mode
  /// \details It provides the names of the global values that are required to be modified
  virtual ::std::vector<::std::string> getGlobalValueNames() const {
      return ::std::vector<::std::string>();
  }

  /// \brief Dump information
  virtual void dump ( ::llvm::raw_ostream& ) const = 0;

protected:
  AprxTechniqueIdTy Id;  //< Identifier
}; // end class definition
}  // end core namepsace
}  // end bellerophon namespace
#endif /* INCLUDE_BELLEROPHON_APRXTECHNIQUE_H_ */
