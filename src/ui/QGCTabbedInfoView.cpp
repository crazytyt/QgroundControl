#include "QGCTabbedInfoView.h"

QGCTabbedInfoView::QGCTabbedInfoView(QWidget *parent) : QWidget(parent)
{
    ui.setupUi(this);
    messageView = new UASMessageViewWidget(this);
    //actionsWidget = new UASActionsWidget(this);
    quickView = new UASQuickView(this);
    //rawView = new UASRawStatusView(this);
    ui.tabWidget->addTab(quickView,tr("Quick"));
    //ui.tabWidget->addTab(actionsWidget,"Actions");
    //ui.tabWidget->addTab(rawView,"Status");
    ui.tabWidget->addTab(messageView,tr("Messages"));
}
void QGCTabbedInfoView::addSource(MAVLinkDecoder *decoder)
{
    m_decoder = decoder;
    //rawView->addSource(decoder);
    quickView->addSource(decoder);
}

QGCTabbedInfoView::~QGCTabbedInfoView()
{
}
