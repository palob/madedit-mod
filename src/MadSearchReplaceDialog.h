///////////////////////////////////////////////////////////////////////////////
// Name:		MadSearchReplaceDialog.h
// Description:
// Author:		madedit@gmail.com
// Maintainer:	minggang.li@gmail.com
// Licence:		GPL
///////////////////////////////////////////////////////////////////////////////

#ifndef	_MADSEARCHREPLACEDIALOG_H_
#define	_MADSEARCHREPLACEDIALOG_H_
#include "MadUtils.h"

#ifdef _MSC_VER
# pragma warning( push )
# pragma warning( disable : 4996 )
#endif
// disable 4996 {
//(*Headers(MadSearchReplaceDialog)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/menu.h>
#include <wx/radiobut.h>
#include <wx/sizer.h>
#include <wx/slider.h>
//*)
// disable 4996 }
#ifdef _MSC_VER
# pragma warning( pop )
#endif

#include <wx/fileconf.h>
#include <wx/bmpbuttn.h>

#include <map>

class MadEdit;
class MadRecentList;

class MadSearchReplaceDialog: public wxDialog
{
	public:

		MadSearchReplaceDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~MadSearchReplaceDialog();

		//(*Declarations(MadSearchReplaceDialog)
		wxBoxSizer* BoxSizer4;
		wxBoxSizer* BoxSizerReplace;
		wxBoxSizer* BoxSizerSearch;
		wxButton* WxButtonClose;
		wxButton* WxButtonCount;
		wxButton* WxButtonFindAll;
		wxButton* WxButtonFindAllInAll;
		wxButton* WxButtonFindNext;
		wxButton* WxButtonFindPrev;
		wxButton* WxButtonReplace;
		wxButton* WxButtonReplaceAll;
		wxButton* WxButtonReplaceAllInAll;
		wxButton* WxButtonReplaceExpand;
		wxCheckBox* WxCheckBoxBookmarkLine;
		wxCheckBox* WxCheckBoxBookmarkOnly;
		wxCheckBox* WxCheckBoxCaseSensitive;
		wxCheckBox* WxCheckBoxDotMatchNewLine;
		wxCheckBox* WxCheckBoxFindHex;
		wxCheckBox* WxCheckBoxMoveFocus;
		wxCheckBox* WxCheckBoxPurgeBookmark;
		wxCheckBox* WxCheckBoxRegex;
		wxCheckBox* WxCheckBoxSearchInSelection;
		wxCheckBox* WxCheckBoxWholeWord;
		wxCheckBox* WxCheckBoxWrapAround;
		wxCheckBox* wxCheckBoxReplaceNoDoubleCheck;
		wxMenu WxPopupMenuRecentFindText;
		wxMenu WxPopupMenuRecentReplaceText;
		wxRadioButton* WxRadioAlways;
		wxRadioButton* WxRadioLosingFocus;
		wxSlider* WxSliderInputSizer;
		wxSlider* WxSliderTransDegree;
		//*)

	protected:

		//(*Identifiers(MadSearchReplaceDialog)
		//*)

		static const long ID_RECENTFINDTEXT1;	// must be the same with MadSearchDialog
		static const long ID_RECENTFINDTEXT20;
		static const long ID_RECENTREPLACETEXT1;
		static const long ID_RECENTREPLACETEXT20;
	public:
		wxFileOffset m_SearchFrom;
		wxFileOffset m_SearchTo;
		bool m_EnableTransparency;
		bool m_ReplaceDlgUi;

		MadEdit *m_FindText, *m_ReplaceText;
		wxBitmapButton *WxBitmapButtonRecentFindText, *WxBitmapButtonRecentReplaceText;
		MadRecentList *m_RecentFindText;
		MadRecentList *m_RecentReplaceText;
		wxSize m_OriginInputSize;

		void ReadWriteSettings(bool bRead);
		void UpdateCheckBoxByCBHex(bool check);
		void UpdateSearchInSelection(bool check);


	//private:
	public:
		//(*Handlers(MadSearchReplaceDialog)
		void MadSearchReplaceDialogClose(wxCloseEvent& event);
		void MadSearchReplaceDialogKeyDown(wxKeyEvent& event);
		void WxCheckBoxFindHexClick(wxCommandEvent& event);
		void WxCheckBoxSearchInSelectionClick(wxCommandEvent& event);
		void WxButtonFindNextClick(wxCommandEvent& event);
		void WxButtonReplaceClick(wxCommandEvent& event);
		void WxButtonReplaceAllClick(wxCommandEvent& event);
		void WxButtonFindPrevClick(wxCommandEvent& event);
		void WxButtonCountClick(wxCommandEvent& event);
		void WxButtonCloseClick(wxCommandEvent& event);
		void WxButtonReplaceExpandClick(wxCommandEvent& event);
		void WxCheckBoxRegexClick(wxCommandEvent& event);
		void WxRadioLosingFocusSelect(wxCommandEvent& event);
		void WxRadioAlwaysSelect(wxCommandEvent& event);
		void WxSliderTransDegreeScroll(wxCommandEvent& event);
		void WxButtonReplaceAllInAllClick(wxCommandEvent& event);
		void WxButtonFindAllClick(wxCommandEvent& event);
		void WxButtonFindAllInAllClick(wxCommandEvent& event);
		void OnWxSliderInputSizerCmdScroll(wxCommandEvent& event);
		void WxCheckBoxBookmarkLineClick(wxCommandEvent& event);
		//*)

		void MadSearchReplaceDialogActivate(wxActivateEvent& event);

		void WxBitmapButtonRecentFindTextClick(wxCommandEvent& event);
		void WxBitmapButtonRecentReplaceTextClick(wxCommandEvent& event);
		void OnRecentFindText(wxCommandEvent& event);
		void OnRecentReplaceText(wxCommandEvent& event);

		void PurgeRecentFindTexts();
		void PurgeRecentReplaceTexts();
		void ReplaceAll(MadEdit	* madedit, bool	needRec=true);
		void SearchAll(MadEdit * madedit, bool needRec=true);
		void ShowReplaceUI();
		void SetTransparency();
		void ShowFindUI();
};

extern MadSearchReplaceDialog *g_SearchReplaceDialog;

#endif
