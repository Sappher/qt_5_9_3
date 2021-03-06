// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef FPDFSDK_JAVASCRIPT_DOCUMENT_H_
#define FPDFSDK_JAVASCRIPT_DOCUMENT_H_

#include <list>
#include <memory>
#include <vector>

#include "core/fpdfapi/page/cpdf_pageobject.h"
#include "core/fpdfapi/page/cpdf_textobject.h"
#include "fpdfsdk/cpdfsdk_formfillenvironment.h"
#include "fpdfsdk/javascript/JS_Define.h"

class PrintParamsObj : public CJS_EmbedObj {
 public:
  explicit PrintParamsObj(CJS_Object* pJSObject);
  ~PrintParamsObj() override {}

 public:
  bool bUI;
  int nStart;
  int nEnd;
  bool bSilent;
  bool bShrinkToFit;
  bool bPrintAsImage;
  bool bReverse;
  bool bAnnotations;
};

class CJS_PrintParamsObj : public CJS_Object {
 public:
  explicit CJS_PrintParamsObj(v8::Local<v8::Object> pObject)
      : CJS_Object(pObject) {}
  ~CJS_PrintParamsObj() override {}

  DECLARE_JS_CLASS();
};

class Icon;
class Field;

struct IconElement {
  IconElement(const CFX_WideString& name, Icon* stream)
      : IconName(name), IconStream(stream) {}

  const CFX_WideString IconName;
  Icon* const IconStream;
};

struct CJS_DelayData;
struct CJS_DelayAnnot;
struct CJS_AnnotObj;

class Document : public CJS_EmbedObj {
 public:
  explicit Document(CJS_Object* pJSObject);
  ~Document() override;

  bool ADBE(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool author(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool baseURL(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool bookmarkRoot(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool calculate(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool Collab(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool creationDate(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool creator(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool delay(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool dirty(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool documentFileName(IJS_Context* cc,
                        CJS_PropValue& vp,
                        CFX_WideString& sError);
  bool external(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool filesize(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool icons(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool info(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool keywords(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool layout(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool media(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool modDate(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool mouseX(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool mouseY(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool numFields(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool numPages(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool pageNum(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool pageWindowRect(IJS_Context* cc,
                      CJS_PropValue& vp,
                      CFX_WideString& sError);
  bool path(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool producer(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool subject(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool title(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool zoom(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);
  bool zoomType(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);

  bool addAnnot(IJS_Context* cc,
                const std::vector<CJS_Value>& params,
                CJS_Value& vRet,
                CFX_WideString& sError);
  bool addField(IJS_Context* cc,
                const std::vector<CJS_Value>& params,
                CJS_Value& vRet,
                CFX_WideString& sError);
  bool addLink(IJS_Context* cc,
               const std::vector<CJS_Value>& params,
               CJS_Value& vRet,
               CFX_WideString& sError);
  bool addIcon(IJS_Context* cc,
               const std::vector<CJS_Value>& params,
               CJS_Value& vRet,
               CFX_WideString& sError);
  bool calculateNow(IJS_Context* cc,
                    const std::vector<CJS_Value>& params,
                    CJS_Value& vRet,
                    CFX_WideString& sError);
  bool closeDoc(IJS_Context* cc,
                const std::vector<CJS_Value>& params,
                CJS_Value& vRet,
                CFX_WideString& sError);
  bool createDataObject(IJS_Context* cc,
                        const std::vector<CJS_Value>& params,
                        CJS_Value& vRet,
                        CFX_WideString& sError);
  bool deletePages(IJS_Context* cc,
                   const std::vector<CJS_Value>& params,
                   CJS_Value& vRet,
                   CFX_WideString& sError);
  bool exportAsText(IJS_Context* cc,
                    const std::vector<CJS_Value>& params,
                    CJS_Value& vRet,
                    CFX_WideString& sError);
  bool exportAsFDF(IJS_Context* cc,
                   const std::vector<CJS_Value>& params,
                   CJS_Value& vRet,
                   CFX_WideString& sError);
  bool exportAsXFDF(IJS_Context* cc,
                    const std::vector<CJS_Value>& params,
                    CJS_Value& vRet,
                    CFX_WideString& sError);
  bool extractPages(IJS_Context* cc,
                    const std::vector<CJS_Value>& params,
                    CJS_Value& vRet,
                    CFX_WideString& sError);
  bool getAnnot(IJS_Context* cc,
                const std::vector<CJS_Value>& params,
                CJS_Value& vRet,
                CFX_WideString& sError);
  bool getAnnots(IJS_Context* cc,
                 const std::vector<CJS_Value>& params,
                 CJS_Value& vRet,
                 CFX_WideString& sError);
  bool getAnnot3D(IJS_Context* cc,
                  const std::vector<CJS_Value>& params,
                  CJS_Value& vRet,
                  CFX_WideString& sError);
  bool getAnnots3D(IJS_Context* cc,
                   const std::vector<CJS_Value>& params,
                   CJS_Value& vRet,
                   CFX_WideString& sError);
  bool getField(IJS_Context* cc,
                const std::vector<CJS_Value>& params,
                CJS_Value& vRet,
                CFX_WideString& sError);
  bool getIcon(IJS_Context* cc,
               const std::vector<CJS_Value>& params,
               CJS_Value& vRet,
               CFX_WideString& sError);
  bool getLinks(IJS_Context* cc,
                const std::vector<CJS_Value>& params,
                CJS_Value& vRet,
                CFX_WideString& sError);
  bool getNthFieldName(IJS_Context* cc,
                       const std::vector<CJS_Value>& params,
                       CJS_Value& vRet,
                       CFX_WideString& sError);
  bool getOCGs(IJS_Context* cc,
               const std::vector<CJS_Value>& params,
               CJS_Value& vRet,
               CFX_WideString& sError);
  bool getPageBox(IJS_Context* cc,
                  const std::vector<CJS_Value>& params,
                  CJS_Value& vRet,
                  CFX_WideString& sError);
  bool getPageNthWord(IJS_Context* cc,
                      const std::vector<CJS_Value>& params,
                      CJS_Value& vRet,
                      CFX_WideString& sError);
  bool getPageNthWordQuads(IJS_Context* cc,
                           const std::vector<CJS_Value>& params,
                           CJS_Value& vRet,
                           CFX_WideString& sError);
  bool getPageNumWords(IJS_Context* cc,
                       const std::vector<CJS_Value>& params,
                       CJS_Value& vRet,
                       CFX_WideString& sError);
  bool getPrintParams(IJS_Context* cc,
                      const std::vector<CJS_Value>& params,
                      CJS_Value& vRet,
                      CFX_WideString& sError);
  bool getURL(IJS_Context* cc,
              const std::vector<CJS_Value>& params,
              CJS_Value& vRet,
              CFX_WideString& sError);
  bool gotoNamedDest(IJS_Context* cc,
                     const std::vector<CJS_Value>& params,
                     CJS_Value& vRet,
                     CFX_WideString& sError);
  bool importAnFDF(IJS_Context* cc,
                   const std::vector<CJS_Value>& params,
                   CJS_Value& vRet,
                   CFX_WideString& sError);
  bool importAnXFDF(IJS_Context* cc,
                    const std::vector<CJS_Value>& params,
                    CJS_Value& vRet,
                    CFX_WideString& sError);
  bool importTextData(IJS_Context* cc,
                      const std::vector<CJS_Value>& params,
                      CJS_Value& vRet,
                      CFX_WideString& sError);
  bool insertPages(IJS_Context* cc,
                   const std::vector<CJS_Value>& params,
                   CJS_Value& vRet,
                   CFX_WideString& sError);
  bool mailForm(IJS_Context* cc,
                const std::vector<CJS_Value>& params,
                CJS_Value& vRet,
                CFX_WideString& sError);
  bool print(IJS_Context* cc,
             const std::vector<CJS_Value>& params,
             CJS_Value& vRet,
             CFX_WideString& sError);
  bool removeField(IJS_Context* cc,
                   const std::vector<CJS_Value>& params,
                   CJS_Value& vRet,
                   CFX_WideString& sError);
  bool replacePages(IJS_Context* cc,
                    const std::vector<CJS_Value>& params,
                    CJS_Value& vRet,
                    CFX_WideString& sError);
  bool resetForm(IJS_Context* cc,
                 const std::vector<CJS_Value>& params,
                 CJS_Value& vRet,
                 CFX_WideString& sError);
  bool saveAs(IJS_Context* cc,
              const std::vector<CJS_Value>& params,
              CJS_Value& vRet,
              CFX_WideString& sError);
  bool submitForm(IJS_Context* cc,
                  const std::vector<CJS_Value>& params,
                  CJS_Value& vRet,
                  CFX_WideString& sError);
  bool syncAnnotScan(IJS_Context* cc,
                     const std::vector<CJS_Value>& params,
                     CJS_Value& vRet,
                     CFX_WideString& sError);
  bool mailDoc(IJS_Context* cc,
               const std::vector<CJS_Value>& params,
               CJS_Value& vRet,
               CFX_WideString& sError);
  bool removeIcon(IJS_Context* cc,
                  const std::vector<CJS_Value>& params,
                  CJS_Value& vRet,
                  CFX_WideString& sError);
  bool URL(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError);

  void SetFormFillEnv(CPDFSDK_FormFillEnvironment* pFormFillEnv);
  CPDFSDK_FormFillEnvironment* GetFormFillEnv() const {
    return m_pFormFillEnv.Get();
  }
  void AddDelayData(CJS_DelayData* pData);
  void DoFieldDelay(const CFX_WideString& sFieldName, int nControlIndex);
  CJS_Document* GetCJSDoc() const;

 private:
  bool IsEnclosedInRect(CFX_FloatRect rect, CFX_FloatRect LinkRect);
  int CountWords(CPDF_TextObject* pTextObj);
  CFX_WideString GetObjWordStr(CPDF_TextObject* pTextObj, int nWordIndex);

  bool getPropertyInternal(IJS_Context* cc,
                           CJS_PropValue& vp,
                           const CFX_ByteString& propName,
                           CFX_WideString& sError);

  CPDFSDK_FormFillEnvironment::ObservedPtr m_pFormFillEnv;
  CFX_WideString m_cwBaseURL;
  std::list<std::unique_ptr<CJS_DelayData>> m_DelayData;
  std::list<std::unique_ptr<IconElement>> m_Icons;  // For iterator stability.
  bool m_bDelay;
};

class CJS_Document : public CJS_Object {
 public:
  explicit CJS_Document(v8::Local<v8::Object> pObject) : CJS_Object(pObject) {}
  ~CJS_Document() override {}

  // CJS_Object
  void InitInstance(IJS_Runtime* pIRuntime) override;

  DECLARE_JS_CLASS();

  JS_STATIC_PROP(ADBE, Document);
  JS_STATIC_PROP(author, Document);
  JS_STATIC_PROP(baseURL, Document);
  JS_STATIC_PROP(bookmarkRoot, Document);
  JS_STATIC_PROP(calculate, Document);
  JS_STATIC_PROP(Collab, Document);
  JS_STATIC_PROP(creationDate, Document);
  JS_STATIC_PROP(creator, Document);
  JS_STATIC_PROP(delay, Document);
  JS_STATIC_PROP(dirty, Document);
  JS_STATIC_PROP(documentFileName, Document);
  JS_STATIC_PROP(external, Document);
  JS_STATIC_PROP(filesize, Document);
  JS_STATIC_PROP(icons, Document);
  JS_STATIC_PROP(info, Document);
  JS_STATIC_PROP(keywords, Document);
  JS_STATIC_PROP(layout, Document);
  JS_STATIC_PROP(media, Document);
  JS_STATIC_PROP(modDate, Document);
  JS_STATIC_PROP(mouseX, Document);
  JS_STATIC_PROP(mouseY, Document);
  JS_STATIC_PROP(numFields, Document);
  JS_STATIC_PROP(numPages, Document);
  JS_STATIC_PROP(pageNum, Document);
  JS_STATIC_PROP(pageWindowRect, Document);
  JS_STATIC_PROP(path, Document);
  JS_STATIC_PROP(producer, Document);
  JS_STATIC_PROP(subject, Document);
  JS_STATIC_PROP(title, Document);
  JS_STATIC_PROP(URL, Document);
  JS_STATIC_PROP(zoom, Document);
  JS_STATIC_PROP(zoomType, Document);

  JS_STATIC_METHOD(addAnnot, Document);
  JS_STATIC_METHOD(addField, Document);
  JS_STATIC_METHOD(addLink, Document);
  JS_STATIC_METHOD(addIcon, Document);
  JS_STATIC_METHOD(calculateNow, Document);
  JS_STATIC_METHOD(closeDoc, Document);
  JS_STATIC_METHOD(createDataObject, Document);
  JS_STATIC_METHOD(deletePages, Document);
  JS_STATIC_METHOD(exportAsText, Document);
  JS_STATIC_METHOD(exportAsFDF, Document);
  JS_STATIC_METHOD(exportAsXFDF, Document);
  JS_STATIC_METHOD(extractPages, Document);
  JS_STATIC_METHOD(getAnnot, Document);
  JS_STATIC_METHOD(getAnnots, Document);
  JS_STATIC_METHOD(getAnnot3D, Document);
  JS_STATIC_METHOD(getAnnots3D, Document);
  JS_STATIC_METHOD(getField, Document);
  JS_STATIC_METHOD(getIcon, Document);
  JS_STATIC_METHOD(getLinks, Document);
  JS_STATIC_METHOD(getNthFieldName, Document);
  JS_STATIC_METHOD(getOCGs, Document);
  JS_STATIC_METHOD(getPageBox, Document);
  JS_STATIC_METHOD(getPageNthWord, Document);
  JS_STATIC_METHOD(getPageNthWordQuads, Document);
  JS_STATIC_METHOD(getPageNumWords, Document);
  JS_STATIC_METHOD(getPrintParams, Document);
  JS_STATIC_METHOD(getURL, Document);
  JS_STATIC_METHOD(gotoNamedDest, Document);
  JS_STATIC_METHOD(importAnFDF, Document);
  JS_STATIC_METHOD(importAnXFDF, Document);
  JS_STATIC_METHOD(importTextData, Document);
  JS_STATIC_METHOD(insertPages, Document);
  JS_STATIC_METHOD(mailForm, Document);
  JS_STATIC_METHOD(print, Document);
  JS_STATIC_METHOD(removeField, Document);
  JS_STATIC_METHOD(replacePages, Document);
  JS_STATIC_METHOD(removeIcon, Document);
  JS_STATIC_METHOD(resetForm, Document);
  JS_STATIC_METHOD(saveAs, Document);
  JS_STATIC_METHOD(submitForm, Document);
  JS_STATIC_METHOD(syncAnnotScan, Document);
  JS_STATIC_METHOD(mailDoc, Document);
};

#endif  // FPDFSDK_JAVASCRIPT_DOCUMENT_H_
