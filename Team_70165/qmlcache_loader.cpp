#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>

static const unsigned char qt_resource_tree[] = {
0,
0,0,0,0,2,0,0,0,5,0,0,0,1,0,0,0,
40,0,0,0,0,0,1,0,0,0,0,0,0,0,100,0,
0,0,0,0,1,0,0,0,0,0,0,0,72,0,0,0,
0,0,1,0,0,0,0,0,0,0,126,0,0,0,0,0,
1,0,0,0,0,0,0,0,8,0,0,0,0,0,1,0,
0,0,0};
static const unsigned char qt_resource_names[] = {
0,
1,0,0,0,47,0,47,0,13,12,6,184,220,0,85,0,
99,0,98,0,111,0,121,0,117,0,116,0,108,0,117,0,
46,0,113,0,109,0,108,0,13,2,41,8,92,0,76,0,
105,0,115,0,116,0,97,0,115,0,97,0,109,0,97,0,
46,0,113,0,109,0,108,0,11,11,246,137,28,0,67,0,
104,0,97,0,114,0,116,0,115,0,50,0,46,0,113,0,
109,0,108,0,10,9,191,109,60,0,67,0,104,0,97,0,
114,0,116,0,115,0,46,0,113,0,109,0,108,0,11,11,
249,137,28,0,67,0,104,0,97,0,114,0,116,0,115,0,
51,0,46,0,113,0,109,0,108};
static const unsigned char qt_resource_empty_payout[] = { 0, 0, 0, 0, 0 };
QT_BEGIN_NAMESPACE
extern Q_CORE_EXPORT bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
QT_END_NAMESPACE
namespace QmlCacheGeneratedCode {
namespace _0x5f__Charts3_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__Charts_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__Charts2_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__Listasama_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__Ucboyutlu_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
        resourcePathToCachedUnit.insert(QStringLiteral("/Charts3.qml"), &QmlCacheGeneratedCode::_0x5f__Charts3_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Charts.qml"), &QmlCacheGeneratedCode::_0x5f__Charts_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Charts2.qml"), &QmlCacheGeneratedCode::_0x5f__Charts2_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Listasama.qml"), &QmlCacheGeneratedCode::_0x5f__Listasama_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Ucboyutlu.qml"), &QmlCacheGeneratedCode::_0x5f__Ucboyutlu_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.version = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
QT_PREPEND_NAMESPACE(qRegisterResourceData)(/*version*/0x01, qt_resource_tree, qt_resource_names, qt_resource_empty_payout);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_Resources)() {
    ::unitRegistry();
    Q_INIT_RESOURCE(Resources_qmlcache);
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_Resources))
int QT_MANGLE_NAMESPACE(qCleanupResources_Resources)() {
    Q_CLEANUP_RESOURCE(Resources_qmlcache);
    return 1;
}
