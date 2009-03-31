#include <QVariant>
#include <QObject>
#include <QIcon>
#include <QtPlugin>
#include <QDesignerCustomWidgetInterface>
#include <QDesignerFormEditorInterface>
#include <QDesignerPropertyEditorInterface>

#include "ratingwidgetplugin.h"

#include "RatingWidget.h"

RatingWidgetPlugin::RatingWidgetPlugin(QObject *parent) : QObject(parent)
{
	initialized = false;
}

RatingWidgetPlugin::~RatingWidgetPlugin()
{
	delete pluginIcon;
}

bool RatingWidgetPlugin::isContainer() const
{
	return false;
}

bool RatingWidgetPlugin::isInitialized() const
{
	return initialized;
}

QIcon RatingWidgetPlugin::icon() const
{
	return *pluginIcon;
}

QString RatingWidgetPlugin::domXml() const
{
	QString str("");
	str += "<ui language=\"c++\">\n";
	str += " <widget class=\"RatingWidget\" name=\"RatingWidget\">\n";
	str += "  <property name=\"geometry\">\n";
	str += "   <rect>\n";
	str += "    <x>0</x>\n";
	str += "    <y>0</y>\n";
	str += "    <width>%1</width>\n";
	str += "    <height>%2</height>\n";
	str += "   </rect>\n";
	str += "  </property>\n";
	str += "  <property name=\"max\">\n";
	str += "   <number>%3</number>\n";
	str += "  </property>\n";
	str += " </widget>\n";
	str += "</ui>";

	str.arg((32 + 4) * 5); //width
	str.arg(32 + 8); //height
	str.arg(5); //max

	return str;
}

QString RatingWidgetPlugin::group() const
{
	return "Custom Widgets";
}

QString RatingWidgetPlugin::includeFile() const
{
	return "RatingWidget.h";
}

QString RatingWidgetPlugin::name() const
{
	return "RatingWidget";
}

QString RatingWidgetPlugin::toolTip() const
{
	//TODO ?????
	return "";
}

QString RatingWidgetPlugin::whatsThis() const
{
	//TODO ?????
	return "";
}

QWidget* RatingWidgetPlugin::createWidget(QWidget *parent)
{
	return new RatingWidget(parent);
}

void RatingWidgetPlugin::initialize(QDesignerFormEditorInterface *core)
{
	if (initialized)
		return;

	pluginIcon = new QIcon("fullstar.gif");
	connect(core->propertyEditor(), SIGNAL(propertyChanged(QString,QVariant)), this, SLOT(setProperties(QString,QVariant)));

	initialized = true;
}

void RatingWidgetPlugin::setProperties(QString prop, QVariant value)
{
	if(prop == "max")
		max = value.toInt();
}

Q_EXPORT_PLUGIN2(RatingWidgetPlugin, RatingWidgetPlugin)
