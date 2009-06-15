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
#ifndef RATINGWIDGETPLUGIN_H
#define RATINGWIDGETPLUGIN_H

#include <QVariant>
#include <QObject>
#include <QDesignerCustomWidgetInterface>

class QIcon;

class RatingWidgetPlugin : public QObject, public QDesignerCustomWidgetInterface
{
	Q_OBJECT
	Q_INTERFACES(QDesignerCustomWidgetInterface)

	public:
		RatingWidgetPlugin(QObject *parent = 0);
		~RatingWidgetPlugin();

		//required by QDesignerCustomWidgetInterface
		bool isContainer() const;
		bool isInitialized() const;
		QIcon icon() const;
		QString domXml() const;
		QString group() const;
		QString includeFile() const;
		QString name() const;
		QString toolTip() const;
		QString whatsThis() const;
		QWidget *createWidget(QWidget *parent);
		void initialize(QDesignerFormEditorInterface *core);

	private:
		bool initialized;
		QIcon *pluginIcon;
};

#endif // RATINGWIDGETPLUGIN_H
