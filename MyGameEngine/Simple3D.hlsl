
Texture2D g_texture : register(t0);
SamplerState g_sampler : register(s0);
cbuffer global
{
    float4x4 matWVP;
    float4x4 matW;
};
struct VS_OUT
{
    float4 pos : SV_POSITION;
    float2 uv : TEXCOORD;
    float4 cos_alpha : COLOR;
};
VS_OUT VS(float4 pos : POSITION, float4 uv : TEXCOORD, float4 normal : NORMAL)
{
    VS_OUT outData;
    outData.pos = mul(pos, matWVP);
    outData.uv = uv;
    float4 light = float4(1, 1, -1, 0);
    light = normalize(light);
    normal = mul(normal, matW);
    normal = normalize(normal);
    normal.w = 0;
    light.w = 0;
    outData.cos_alpha = clamp(dot(normal, light), 0, 1);
    return outData;
}
float4 PS(VS_OUT inData) : SV_Target
{
    float4 Id = { 1.0, 1.0, 1.0, 1.0 };
    float4 Kd = g_texture.Sample(g_sampler, inData.uv);
    float cos_alpha = inData.cos_alpha;
    float4 ambentSource = { 0.3, 0.3, 0.3, 1.0 };
    return Id * Kd * cos_alpha + Id * Kd * ambentSource;
}