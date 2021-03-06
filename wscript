#! /usr/bin/env python

# the following two variables are used by the target "waf dist"
VERSION='0'
APPNAME='aprsmap'

# these variables are mandatory ('/' are converted automatically)
top = '.'
out = 'build'

def options(opt):
    opt.tool_options('compiler_cc')

def configure(conf):
    conf.check_tool('compiler_cc')
    conf.check(header_name='stdlib.h')
    conf.check(header_name='math.h')

    conf.env.CCFLAGS = ['-O0', '-g3']
    conf.check_cfg(package='gtk+-2.0', uselib_store='GTK', atleast_version='2.6.0', mandatory=True, args='--cflags --libs')
    conf.check_cfg(package='gmodule-2.0', uselib_store='GMODULE', atleast_version='2.18.0', args='--cflags --libs')
    conf.check_cfg(package = 'osmgpsmap', uselib_store='OSMGPSMAP', atleast_version = '0.7.2', args = '--cflags --libs')
    conf.check_cfg(package="libfap", uselib_store="FAP", atleast_version = '1.1', args = '--cflags --libs')
def build(bld):
    # aprsmap
    bld(
        features = 'c cprogram',
        source = ['aprsis.c', 'callbacks.c', 'mapviewer.c', 'station.c'],
        target = 'aprsmap',
        uselib = "GTK OSMGPSMAP FAP GMODULE",
        includes = '. /usr/include')


