#include "addpolicydialog.h"
#include "newpolicytab.h"

#include <QtWidgets>

NewPolicyTab::NewPolicyTab(QWidget *parent)
{
    Q_UNUSED(parent);

    descriptionLabel = new QLabel(tr("Baza polis jest pusta. "
                                      " Użyj przycisku poniżej aby to zmienić."));

    addButton = new QPushButton(tr("Dodaj polise"));

    connect(addButton, &QAbstractButton::clicked, this, &NewPolicyTab::addEntry);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(descriptionLabel);
    mainLayout->addWidget(addButton, 0, Qt::AlignCenter);

    setLayout(mainLayout);
}
void NewPolicyTab::addEntry()
{
    AddPolicyDialog aDialog;

    if (aDialog.exec()) {
        QString type = aDialog.typeText->text();
        QString company = aDialog.companyText->text();
        QString num = aDialog.numText->text();
        QString period = aDialog.periodText->text();

        emit sendDetails(type, company, num, period);
    }
}
