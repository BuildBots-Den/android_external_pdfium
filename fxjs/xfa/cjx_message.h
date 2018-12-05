// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef FXJS_XFA_CJX_MESSAGE_H_
#define FXJS_XFA_CJX_MESSAGE_H_

#include "fxjs/jse_define.h"
#include "fxjs/xfa/cjx_node.h"

class CXFA_Message;

class CJX_Message final : public CJX_Node {
 public:
  explicit CJX_Message(CXFA_Message* node);
  ~CJX_Message() override;
};

#endif  // FXJS_XFA_CJX_MESSAGE_H_
