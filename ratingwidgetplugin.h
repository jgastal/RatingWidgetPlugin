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

	protected slots:
		void setProperties(QString prop, QVariant value);

	private:
		bool initialized;
		QIcon *pluginIcon;
		int max;
};

#endif // RATINGWIDGETPLUGIN_H
