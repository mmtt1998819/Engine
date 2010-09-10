#pragma once

#include "Editor/Inspect/Widget.h"

namespace Helium
{
    namespace Editor
    {
        class LabelWidget;

        class LabelWindow : public wxPanel
        {
        public:
            LabelWindow(wxWindow* parent, LabelWidget* labelWidget);

            wxString GetLabel() const;
            void SetLabel(const wxString& label);

            void UpdateHelpText( const wxString& helpText );

            virtual bool SetForegroundColour(const wxColour& color) HELIUM_OVERRIDE;
            virtual bool SetBackgroundColour(const wxColour& color) HELIUM_OVERRIDE;

        private:
            LabelWidget*    m_LabelWidget;
            wxStaticText*   m_StaticText;
        };

        class LabelWidget : public Reflect::ConcreteInheritor< LabelWidget, Widget >
        {
        public:
            LabelWidget()
                : m_LabelControl( NULL )
                , m_LabelWindow( NULL )
            {

            }

            LabelWidget( Inspect::Label* label );

            virtual void Create( wxWindow* parent ) HELIUM_OVERRIDE;
            virtual void Destroy() HELIUM_OVERRIDE;

            // Inspect::Widget
            virtual void Read() HELIUM_OVERRIDE;
            virtual bool Write() HELIUM_OVERRIDE;

            // Editor::Widget
            virtual void HelpTextChanged( const Attribute<tstring>::ChangeArgs& args ) HELIUM_OVERRIDE;

        protected:
            Inspect::Label*     m_LabelControl;
            LabelWindow*        m_LabelWindow;
        };
    }
}