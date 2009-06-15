/*
 *  Copyright (C) 2009 Jonas Mauricio Gastal.
 *  Contact: Jonas Mauricio Gastal (jgastal@gmail.com)
 *
 *  This file is part of RatingWidgetPlugin.
 *
 *  RatingWidgetPlugin is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License.
 *
 *  Parabola Biblioteca is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with RatingWidgetPlugin.  If not, see <http://www.gnu.org/licenses/>.
 */
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
