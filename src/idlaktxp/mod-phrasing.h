// idlaktxp/mod-phrasing.h

// Copyright 2012 CereProc Ltd.  (Author: Matthew Aylett)

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
// THIS CODE IS PROVIDED *AS IS* BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION ANY IMPLIED
// WARRANTIES OR CONDITIONS OF TITLE, FITNESS FOR A PARTICULAR PURPOSE,
// MERCHANTABLITY OR NON-INFRINGEMENT.
// See the Apache 2 License for the specific language governing permissions and
// limitations under the License.
//

#ifndef KALDI_IDLAKTXP_MOD_PHRASING_H_
#define KALDI_IDLAKTXP_MOD_PHRASING_H_

// This file defines the basic txp module which incrementally parses
// either text, tox (token oriented xml) tokens, or spurts (phrases)
// containing tox tokens.

#include <string>
#include "pugixml.hpp"

#include "base/kaldi-common.h"
#include "idlaktxp/idlak-common.h"
#include "idlaktxp/txpmodule.h"

namespace kaldi {

/// Using pauses contruct a phrase structure in the XML
/// by adding spt elements. /ref idlaktxp_phrase
class TxpPhrasing : public TxpModule {
 public:
  explicit TxpPhrasing();
  ~TxpPhrasing();
  bool Init(const TxpParseOptions &opts);
  bool Process(pugi::xml_document* input);

 private:
  /// Process a file (documents may have several files of information separated
  /// within file id elements).
  bool ProcessFile(pugi::xml_node* file);
};

}  // namespace kaldi

#endif  // KALDI_IDLAKTXP_MOD_PHRASING_H_
