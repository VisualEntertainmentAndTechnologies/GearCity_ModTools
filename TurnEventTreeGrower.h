/*Copyright 2016 Visual Entertainment And Technologies, LLC. All Rights Reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

- Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

- Neither the name of Visual Entertainment And Technologies, LLC
nor the names of its contributors may be used to endorse or promote products
derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.")*/


/* *
 * CODING GUIDELINES...
 * Allman Indent Style!
 * 100 +/- Column Width
 * Avoid Namespaces
 * Lower Camel Case for variables and functions.
 * Upper Camel Case for everything else. (UI Widgets, Class Names)
 * Don't shoot me if I forget these things as well...
 * */


#ifndef TURNEVENTTREEGROWER_H
#define TURNEVENTTREEGROWER_H
#include <QMap>
#include <QTreeWidget>
#include "TurnEventsData.h"
#include <QString>
#include "LocalizationManager.h"
#include <QComboBox>
#include "CityData.h"

class TurnEventTreeGrower
{
public:
    TurnEventTreeGrower(QTreeWidget *tree, QMap<int,TurnData::TE_Data> map,
                        QMap<int, CityData::dataStore> cityMap,
                        int startYearLimit, int finishYearLimit,
                        QComboBox *compCombo,
                        QComboBox *carCombo,
                        LocalizationManager *lm = 0);
private:
    void addSingleValueLeafToTree(QTreeWidgetItem *parent, QString event,
                                  QString valueName, QString valueData);
    void addComponentLeafToTree(QTreeWidgetItem *parent, TurnData::TE_ComponentEvts tecoe,
                                QComboBox *compCombo);
    void addCityLeafToTree(QTreeWidgetItem *parent, TurnData::TE_CityEvts tecie,
                                                QMap<int, CityData::dataStore> cityMap);
    void addNewsLeafToTree(QTreeWidgetItem *parent, TurnData::TE_NewsEvts tene);
    void addVehicleLeafToTree(QTreeWidgetItem *parent,
                                                     TurnData::TE_VehiclePop tevp,
                                                     QComboBox *carCombo);

    LocalizationManager *localManager;
};

#endif // TURNEVENTTREEGROWER_H
