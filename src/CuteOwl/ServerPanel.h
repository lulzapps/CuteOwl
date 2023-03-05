#pragma once
#include <QQuickWidget>

namespace owl
{

class ServerObject
{
    QString _name;
    QString _color;

public:
    ServerObject(const QString& name, const QString& color)
    {
        // nothing to do
    }

    QString name() const { return _name; }
    QString color() const { return _color; }
};

class ServerObjectModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum ServerObjectRoles
    {
        NameRole = Qt::UserRole + 1,
        ColorRole
    };

    ServerObjectModel(QObject* parent = nullptr)
        : QAbstractListModel(parent)
    {
        // nothing to do
    }

    void addServerObject(const ServerObject& animal)
    {
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        _serverObjects << animal;
        endInsertRows();
    }

    int rowCount(const QModelIndex& parent = QModelIndex()) const
    {
        Q_UNUSED(parent);
        return _serverObjects.count();
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const
    {
        if (index.row() < 0 || index.row() >= _serverObjects.count())
        {
            return QVariant();
        }

        const ServerObject& animal = _serverObjects[index.row()];

        if (role == NameRole)
        {
            return animal.name();
        }
        else if (role == ColorRole)
        {
            return animal.color();
        }

        return QVariant();
    }

protected:
    QHash<int, QByteArray> roleNames() const
    {
        QHash<int, QByteArray> roles;
        roles[NameRole] = "name";
        roles[ColorRole] = "color";
        return roles;
    }

private:
    QList<ServerObject> _serverObjects;
};


class ServerPanel : public QWidget
{

Q_OBJECT

public:
    ServerPanel(QWidget* parent = nullptr);
    virtual ~ServerPanel() = default;

};

} // namespace owl
