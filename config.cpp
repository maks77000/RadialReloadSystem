class CfgPatches
{
    class RadialReloadV4
    {
        requiredAddons[] =
        {
            "DZ_Data",
            "DZ_Scripts"
        };
    };
};

class CfgMods
{
    class RadialReloadV4
    {
        type = "mod";

        class defs
        {
            class gameScriptModule
            {
                files[] = { "RadialReloadV4/scripts/3_Game" };
            };

            class worldScriptModule
            {
                files[] = { "RadialReloadV4/scripts/4_world" };
            };

            class missionScriptModule
            {
                files[] = { "RadialReloadV4/scripts/5_mission" };
            };
        };
    };
};

class CfgUserActions
{
    class UAReloadRadial
    {
        displayName = "Radial Reload";
    };
};
