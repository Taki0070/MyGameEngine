//───────────────────────────────────────
// テクスチャ＆サンプラーデータのグローバル変数定義
//───────────────────────────────────────
Texture2D g_texture : register(t0); //テクスチャー
SamplerState g_sampler : register(s0); //サンプラー
//───────────────────────────────────────
// コンスタントバッファ
// DirectX 側から送信されてくる、ポリゴン頂点以外の諸情報の定義
//───────────────────────────────────────
cbuffer global
{
    float4x4 matWVP; // ワールド・ビュー・プロジェクションの合成行列
    float4x4 matW; //ワールド行列
};

//───────────────────────────────────────
// 頂点シェーダー出力＆ピクセルシェーダー入力データ構造体
//───────────────────────────────────────
struct VS_OUT
{
    float4 pos : SV_POSITION; //位置
    float2 uv : TEXCOORD; //UV座標
    float4 cos_alpha : COLOR; //色（明るさ）
    
};

//───────────────────────────────────────
// 頂点シェーダ
//───────────────────────────────────────
VS_OUT VS(float4 pos : POSITION, float4 uv : TEXCOORD, float4 normal : NORMAL)
{
	//ピクセルシェーダーへ渡す情報
    VS_OUT outData;

	//ローカル座標に、ワールド・ビュー・プロジェクション行列をかけて
	//スクリーン座標に変換し、ピクセルシェーダーへ
    outData.pos = mul(pos, matWVP);
    outData.uv = uv;
    
    float4 light = float4(-1, 0.5, -0.3, 0); //光源ベクトルの逆ベクトル 上(0,10,0,0),右(10.0.0.0),左(-10.0.0.0)
    light = normalize(light);   //単位ベクトル化
    
    normal = mul(normal, matW);
    normal = normalize(normal);
        
    outData.cos_alpha = clamp(dot(normal, light),0,1);//clamp は固定,0以下か1以上か
    
    
	//まとめて出力
    return outData;
}

//───────────────────────────────────────
// ピクセルシェーダ
//───────────────────────────────────────
float4 PS(VS_OUT inData) : SV_Target
{
  // return float4(1, 1, 1, 1);
  //  float4 myUv = { 0.125, 0.25, 0, 0 };
    float4 Id = { 1.0, 1.0, 1.0, 1.0 };
    float4 Kd = g_texture.Sample(g_sampler, inData.uv) ;
    float cos_alpha = inData.cos_alpha;
    float4 ambentSource = { 0.3, 0.3, 0.3, 1.0 };//環境光の強さ
    
    return Id * Kd * cos_alpha + Id * Kd * ambentSource;
    
    //float4 diffuse = g_texture.Sample(g_sampler, inData.uv) * inData.cos_alpha;
    //float4 ambient = g_texture.Sample(g_sampler, inData.uv) * float4(0.2, 0.2, 0.2, 1);
    //return diffuse + ambient;
    
    
    //  return g_texture.Sample(g_sampler, inData.uv) * inData.color;
  //   return g_texture.Sample(g_sampler, myUv);//さいころの真ん中を表示
  
}