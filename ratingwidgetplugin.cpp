#include <QVariant>
#include <QObject>
#include <QIcon>
#include <QtPlugin>
#include <QDesignerCustomWidgetInterface>

#include "ratingwidgetplugin.h"
#include "RatingWidget.h"

RatingWidgetPlugin::RatingWidgetPlugin(QObject *parent) : QObject(parent)
{
	initialized = false;
	pluginIcon = new QIcon(":/icons/fullstar.gif");
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
	str += "    <width>176</width>\n";
	str += "    <height>32</height>\n";
	str += "   </rect>\n";
	str += "  </property>\n";
	str += " </widget>\n";
	str += "</ui>";

	return str;
}

QString RatingWidgetPlugin::group() const
{
	return "Input Widgets";
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
	return "";
}

QString RatingWidgetPlugin::whatsThis() const
{
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

	initialized = true;
}

Q_EXPORT_PLUGIN2(RatingWidgetPlugin, RatingWidgetPlugin)
