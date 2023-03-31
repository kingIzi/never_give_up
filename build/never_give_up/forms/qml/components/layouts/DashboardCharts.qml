import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import QtCharts


Item {
    id: _dashboardChartItem
    implicitHeight: _col6.implicitHeight
    ListModel{
        id: _pieChartModel
        ListElement{
            label: "Available"
            value: 30
        }
        ListElement{
            label: "Impending"
            value: 4
        }
    }
    ColumnLayout{
        id: _col6
        anchors.fill: parent
        Item{
            Layout.fillWidth: true
            Layout.preferredHeight: _col7L.implicitHeight
            ColumnLayout{
                id: _col7L
                anchors.fill: parent
                anchors.margins: 10
                Label{
                    id: _piechartTitle
                    text: "Comics in Store"
                    font: Constants.blackFont.h2
                    Material.foreground: Constants.colors.white
                    padding: 10
                }
                Item{
                    id: _piechartItem
                    Layout.fillWidth: true
                    Layout.preferredHeight: 250
                    ChartView{
                        id: _pieChartView
                        anchors.fill: parent
                        theme: ChartView.ChartThemeDark
                        antialiasing: true
                        PieSeries{
                            id: _pieSeries
                            Component.onCompleted: {
                                for (var i = 0; i < _pieChartModel.rowCount(); i++){
                                    let label = _pieChartModel.get(i).label
                                    let value = _pieChartModel.get(i).value
                                    _pieSeries.append(label,value)
                                }
                            }
                        }
                    }
                }
            }
        }
        Item{
            id: _lineSeriesItem
            Layout.fillWidth: true
            Layout.preferredHeight: _col8L.implicitHeight
            function toMsecsSinceEpoch(date){
                return date.getTime()
            }

            ColumnLayout{
                id: _col8L
                anchors.fill: parent
                anchors.margins: 10
                Label{
                    id: _lineSeriesLabel
                    text: "Daily Views"
                    font: Constants.blackFont.h2
                    Material.foreground: Constants.colors.white
                    padding: 10
                }
                Item{
                    id: _lineChartItem
                    Layout.fillWidth: true
                    Layout.preferredHeight: 250
                    ChartView{
                        id: _lineChartView
                        anchors.fill: parent
                        theme: ChartView.ChartThemeDark
                        antialiasing: true
                        LineSeries{
                            id: _lineSeries
                            name: "Views"
                            axisX: DateTimeAxis{
                                format: "dd MMM"
                                tickCount: 5
                            }
                            axisY: ValuesAxis{
                                min: 0
                                max: 150
                            }
                            XYPoint{ x: _lineSeriesItem.toMsecsSinceEpoch(new Date(2023,03,01)); y: 5 }
                            XYPoint{ x: _lineSeriesItem.toMsecsSinceEpoch(new Date(2023,03,02)); y: 50 }
                            XYPoint{ x: _lineSeriesItem.toMsecsSinceEpoch(new Date(2023,03,03)); y: 115 }
                            XYPoint{ x: _lineSeriesItem.toMsecsSinceEpoch(new Date(2023,03,04)); y: 20 }
                            XYPoint{ x: _lineSeriesItem.toMsecsSinceEpoch(new Date(2023,03,05)); y: 34 }
                        }
                    }
                }
            }
        }
    }
}
