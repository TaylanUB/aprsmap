// station.h

#ifndef STATION_H
#define STATION_H

#include <gtk/gtk.h>
#include <osm-gps-map.h>

// GObject macros
#define APRSMAP_TYPE_STATION                  (aprsmap_station_get_type ())
#define APRSMAP_STATION(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), APRSMAP_TYPE_STATION, APRSMapStation))
#define APRSMAP_IS_STATION(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), APRSMAP_TYPE_STATION))
#define APRSMAP_STATION_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), APRSMAP_TYPE_STATION, APRSMapStationClass))
#define APRSMAP_IS_STATION_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), APRSMAP_TYPE_STATION))
#define APRSMAP_STATION_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), APRSMAP_TYPE_STATION, APRSMAPStationClass))

typedef struct _APRSMapStation APRSMapStation;
typedef struct _APRSMapStationClass APRSMapStationClass;



typedef enum {
	APRS_NOFIX,
	APRS_VALIDFIX
} aprs_fix_t;

struct _APRSMapStation {
	GObject parent_instance;
	gchar *callsign;
	gchar symbol[2];
	OsmGpsMapImage *image;
	OsmGpsMapTrack *track;
	GdkPixbuf *pix;
	cairo_surface_t *icon;
	gdouble speed;
	gdouble course;
	gdouble lat, lon;
	aprs_fix_t fix;
};

struct _APRSMapStationClass {
	GObjectClass parent_class;
};
GType aprsmap_station_get_type (void);
gboolean process_packet(gchar *msg);

#endif
/* vim: set noexpandtab ai ts=4 sw=4 tw=4: */
