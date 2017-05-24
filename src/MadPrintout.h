///////////////////////////////////////////////////////////////////////////////
// Name:        MadPrintout.h
// Description: Printing functions
// Author:		madedit@gmail.com
// Maintainer:	minggang.li@gmail.com
// Licence: 	GPL
///////////////////////////////////////////////////////////////////////////////

#ifndef _MADPRINTOUT_H_
#define _MADPRINTOUT_H_
#if __cplusplus <= 199711L
#ifndef nullptr
	#define nullptr (0)
#endif
#endif

class MadPrintout: public wxPrintout
{
    static int s_PrintoutCount;
public:
    MadPrintout(const wxString& title = _("MadEdit-Mod Printout"));
    virtual ~MadPrintout();

    virtual void GetPageInfo(size_t *minPage, size_t *maxPage, size_t *pageFrom, size_t *pageTo);
    virtual bool HasPage(int page);
    virtual bool OnPrintPage(int page);
    
    virtual void OnPreparePrinting();
    
    void CalcPrintInfo(wxPageSetupData *pPageSetupData, double &xScale, double &yScale, wxRect &printRect);
    
    bool m_PrintHeader, m_PrintFooter;
    wxString m_HeaderLeft, m_HeaderCenter, m_HeaderRight;
    wxString m_FooterLeft, m_FooterCenter, m_FooterRight;
    int m_CharHeight, m_HeaderHeight, m_FooterHeight;
};

//extern wxPrintData *g_PrintData;
extern wxPageSetupData* g_PageSetupData;

#endif
