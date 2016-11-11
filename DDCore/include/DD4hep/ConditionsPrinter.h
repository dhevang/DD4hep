//==========================================================================
//  AIDA Detector description implementation for LCD
//--------------------------------------------------------------------------
// Copyright (C) Organisation europeenne pour la Recherche nucleaire (CERN)
// All rights reserved.
//
// For the licensing terms see $DD4hepINSTALL/LICENSE.
// For the list of contributors see $DD4hepINSTALL/doc/CREDITS.
//
// Author     : M.Frank
//
//==========================================================================
#ifndef DD4HEP_DDCOND_CONDITIONSPRINTER_H
#define DD4HEP_DDCOND_CONDITIONSPRINTER_H

// Framework includes
#include "DD4hep/Conditions.h"

/// Namespace for the AIDA detector description toolkit
namespace DD4hep {

  /// Namespace for the AIDA detector description toolkit supporting XML utilities
  namespace Conditions {

    /// Generic Conditions data dumper.
    /**
     *   \author  M.Frank
     *   \version 1.0
     *   \date    31/03/2016
     *   \ingroup DD4HEP_DDDB
     */
    class ConditionsPrinter : public Condition::Processor {
    public:
      std::string   name;
      std::string   prefix;
    protected:
      int           m_flag;

    public:
      typedef Conditions::Condition Cond;

      /// Initializing constructor
      ConditionsPrinter(const std::string& prefix="", 
                        int flag=Cond::NO_NAME|Cond::WITH_IOV|Cond::WITH_ADDRESS);
      /// Set name for printouts
      void setName(const std::string& value)    {  name = value;   }
      /// Set prefix for printouts
      void setPrefix(const std::string& value)  {  prefix = value; }
      /// Callback to output conditions information
      virtual int operator()(Condition cond);
    };

  } /* End namespace Conditions    */
} /* End namespace DD4hep    */

#endif /* DD4HEP_DDCOND_CONDITIONSPRINTER_H  */